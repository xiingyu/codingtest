import csv
import math
import random
from collections import defaultdict
from pathlib import Path

# 로또 6/45 기준
N_MAX = 45
K = 6

def read_nums_csv(path: Path):
    rows = []
    with path.open("r", encoding="utf-8") as f:
        reader = csv.reader(f)
        header = next(reader, None)
        for r in reader:
            if not r:
                continue
            draw = int(r[0])
            nums = list(map(int, r[1:7]))
            rows.append((draw, nums))
    rows.sort(key=lambda x: x[0])  # 회차 오름차순
    return rows

def weighted_sample_without_replacement(items, weights, k, rng: random.Random):
    # Efraimidis-Spirakis: key = U^(1/w) 방식 (w>0)
    # weights가 0이면 선택되지 않도록 제외
    candidates = []
    for item, w in zip(items, weights):
        if w <= 0:
            continue
        u = rng.random()
        key = u ** (1.0 / w)
        candidates.append((key, item))
    candidates.sort(reverse=True)
    return [item for _, item in candidates[:k]]

def recommend_next_numbers(
    rows,
    window=200,
    decay_half_life=80.0,
    cold_penalty_alpha=0.20,
    pair_boost_beta=0.35,
    seed=42,
):
    """
    rows: [(회차, [6개번호]), ...] (오름차순)
    window: 최근 window회만 사용
    decay_half_life: 최근회차에 더 가중 (반감기)
    cold_penalty_alpha: 너무 자주 나온 번호 페널티(0~1)
    pair_boost_beta: 동반출현(pair) 기반 가중 추가(0~1)
    """
    rng = random.Random(seed)

    if not rows:
        raise ValueError("CSV에 데이터가 없습니다.")

    recent = rows[-window:] if len(rows) > window else rows
    draws = [d for d, _ in recent]
    max_draw = draws[-1]

    # 1) 시계열 가중치(최근일수록 큼): weight_t = 2^(-(age)/half_life)
    # age = (max_draw - draw)
    time_w = []
    for d in draws:
        age = max_draw - d
        w = 2.0 ** (-(age) / float(decay_half_life))
        time_w.append(w)

    # 2) 번호별 “최근 가중 빈도”
    freq = [0.0] * (N_MAX + 1)
    last_seen = [None] * (N_MAX + 1)

    for (w, (d, nums)) in zip(time_w, recent):
        for x in nums:
            freq[x] += w
            last_seen[x] = d  # 오름차순이므로 마지막이 최신

    # 3) “최근 미출현” 보너스 (너무 안 나온 번호에 약간 가점)
    # gap = max_draw - last_seen
    gap_bonus = [0.0] * (N_MAX + 1)
    for x in range(1, N_MAX + 1):
        if last_seen[x] is None:
            gap = max_draw  # 거의 없음
        else:
            gap = max_draw - last_seen[x]
        # log로 완만하게: gap 클수록 조금씩 증가
        gap_bonus[x] = math.log(1.0 + gap)

    # 4) “자주 나온 번호” 약간 페널티(과적합 방지 느낌)
    # 정규화 후 (1 - alpha*freq_norm)
    max_f = max(freq[1:]) if max(freq[1:]) > 0 else 1.0
    freq_norm = [f / max_f for f in freq]

    base_score = [0.0] * (N_MAX + 1)
    for x in range(1, N_MAX + 1):
        base = freq_norm[x] + 0.15 * (gap_bonus[x] / (max(gap_bonus[1:]) or 1.0))
        base *= (1.0 - cold_penalty_alpha * freq_norm[x])
        # 아주 작은 값 바닥
        base_score[x] = max(1e-6, base)

    # 5) 동반출현(pair) 기반 보정:
    # 최근 window에서 자주 같이 나온 pair의 점수를 약간 올려줌
    pair_count = defaultdict(float)
    for w, (d, nums) in zip(time_w, recent):
        s = sorted(nums)
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                pair_count[(s[i], s[j])] += w

    # 6개를 한번에 뽑기 전에, base_score로 1차 뽑고,
    # 뽑힌 번호들과의 pair 점수가 큰 후보를 추가 가중해서 2차 재샘플링
    items = list(range(1, N_MAX + 1))
    weights1 = [base_score[i] for i in items]
    first_pick = weighted_sample_without_replacement(items, weights1, K, rng)

    # pair boost 계산
    boosted = base_score[:]
    for x in range(1, N_MAX + 1):
        boost = 0.0
        for a in first_pick:
            i, j = (a, x) if a < x else (x, a)
            if i != j:
                boost += pair_count.get((i, j), 0.0)
        boosted[x] = base_score[x] * (1.0 + pair_boost_beta * (boost))

    weights2 = [boosted[i] for i in items]
    final_pick = weighted_sample_without_replacement(items, weights2, K, rng)
    final_pick.sort()
    return first_pick, final_pick

def main():
    csv_path = Path(__file__).resolve().parent / "nums.csv"
    rows = read_nums_csv(csv_path)

    first, final = recommend_next_numbers(
        rows,
        window=250,
        decay_half_life=90.0,
        cold_penalty_alpha=0.20,
        pair_boost_beta=0.35,
        seed=20251213,  # 시드 바꾸면 다른 조합 나옴
    )

    print(f"데이터 회차 범위: {rows[0][0]} ~ {rows[-1][0]} (총 {len(rows)}회)")
    print("1차 샘플(베이스):", first)
    print("최종 추천(페어 보정):", final)

if __name__ == "__main__":
    main()
