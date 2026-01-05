from __future__ import annotations

import csv
from pathlib import Path
from typing import List, Tuple

import numpy as np
import pandas as pd
from sklearn.linear_model import LogisticRegression
from sklearn.multioutput import MultiOutputClassifier
from sklearn.metrics import average_precision_score


N_MAX = 45
K = 6


def read_nums_csv(path: Path) -> List[Tuple[int, List[int]]]:
    rows = []
    with path.open("r", encoding="utf-8") as f:
        reader = csv.reader(f)
        header = next(reader, None)  # skip header
        for r in reader:
            if not r:
                continue
            draw = int(r[0])
            nums = list(map(int, r[1:7]))
            rows.append((draw, nums))
    rows.sort(key=lambda x: x[0])
    return rows


def to_onehot(nums: List[int]) -> np.ndarray:
    v = np.zeros(N_MAX, dtype=np.float32)
    for x in nums:
        if 1 <= x <= N_MAX:
            v[x - 1] = 1.0
    return v


def build_features_targets(rows: List[Tuple[int, List[int]]], window: int = 20):
    """
    X_t: (t-window ... t-1) 구간의 one-hot들을 이어붙인 벡터 (window*45)
    y_t: t회차의 one-hot (45)
    """
    onehots = [to_onehot(nums) for _, nums in rows]  # len = T
    X, Y = [], []

    for t in range(window, len(onehots)):
        x = np.concatenate(onehots[t - window : t], axis=0)  # (window*45,)
        y = onehots[t]  # (45,)
        X.append(x)
        Y.append(y)

    X = np.stack(X, axis=0)  # (samples, window*45)
    Y = np.stack(Y, axis=0)  # (samples, 45)
    return X, Y


def fit_model(X_train: np.ndarray, Y_train: np.ndarray):
    """
    45개의 이진분류를 동시에 학습 (multi-output logistic regression)
    """
    base = LogisticRegression(
        solver="liblinear",
        max_iter=500,
        class_weight="balanced",
        random_state=42,
    )
    model = MultiOutputClassifier(base, n_jobs=-1)
    model.fit(X_train, Y_train)
    return model


def predict_proba_next(model, x_last: np.ndarray) -> np.ndarray:
    """
    returns p (45,)  각 번호가 나올 확률
    """
    # MultiOutputClassifier: output별로 predict_proba가 따로 나옴
    # 각 output의 predict_proba는 (n_samples, 2) -> class1 확률만 취함
    probas = model.predict_proba(x_last.reshape(1, -1))
    p = np.array([pr[0, 1] for pr in probas], dtype=np.float32)  # (45,)
    return p


def recommend_top6(p: np.ndarray) -> List[int]:
    idx = np.argsort(-p)[:K]  # 내림차순
    nums = sorted((idx + 1).tolist())
    return nums


def backtest(rows: List[Tuple[int, List[int]]], window: int = 20, test_size: int = 200):
    """
    간단한 홀드아웃 백테스트:
    - 앞부분으로 학습
    - 뒷부분 test_size개 샘플로 평가
    평가 지표:
      - hit@6: 추천 6개와 실제 당첨 6개 교집합 개수 평균
      - mAP(평균 정밀도): 45차원 확률을 전체적으로 평가(참고용)
    """
    X, Y = build_features_targets(rows, window=window)
    n = len(X)
    if n <= test_size + 50:
        raise ValueError("데이터가 너무 적습니다. test_size를 줄이거나 window를 줄이세요.")

    split = n - test_size
    X_train, Y_train = X[:split], Y[:split]
    X_test, Y_test = X[split:], Y[split:]

    model = fit_model(X_train, Y_train)

    hits = []
    aps = []
    for i in range(len(X_test)):
        p = predict_proba_next(model, X_test[i])
        pred6 = set(recommend_top6(p))
        true6 = set(np.where(Y_test[i] > 0.5)[0] + 1)
        hits.append(len(pred6 & true6))

        # average_precision_score는 각 라벨에 대해 계산 후 평균(여기선 macro)
        # (주의: 양성이 6개뿐이라 수치가 의미있게 높게 나오기 어렵고, 비교용)
        aps.append(average_precision_score(Y_test[i], p))

    return model, float(np.mean(hits)), float(np.mean(aps))


def main():
    csv_path = Path(__file__).resolve().parent / "nums.csv"
    rows = read_nums_csv(csv_path)

    window = 20       # “최근 20회”를 보고 다음을 예측
    test_size = 200   # 최근 200개 샘플로 평가

    model, hit_mean, map_mean = backtest(rows, window=window, test_size=test_size)
    print(f"[BACKTEST] window={window}, test_size={test_size}")
    print(f"  평균 hit@6 (0~6): {hit_mean:.3f}")
    print(f"  평균 mAP (참고용): {map_mean:.4f}")

    # 최신 회차 기준으로 다음 회차 예측
    X_all, Y_all = build_features_targets(rows, window=window)
    x_last = X_all[-1]
    p_next = predict_proba_next(model, x_last)
    rec = recommend_top6(p_next)

    last_draw = rows[-1][0]
    print(f"\n[RECOMMEND] 다음 회차(현재 최신 {last_draw}회차 이후) 추천 6개:")
    print(rec)


if __name__ == "__main__":
    main()
