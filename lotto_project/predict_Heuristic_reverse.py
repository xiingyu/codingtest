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
        header = next(reader, None)  # 헤더 스킵
        for r in reader:
            if not r:
                continue
            draw = int(r[0])
            nums = list(map(int, r[1:7]))
            rows.append((draw, nums))
    rows.sort(key=lambda x: x[0])  # 회차 오름차순
    return rows


def weighted_sample_without_replacement(items, weights, k, rng: random.Random):
    """
    Efraimidis–Spirakis weighted sampling without replacement
    key = U^(1/w), w>0
    """
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
    window=250,
    decay_half_life=90.0,
    cold_penalty_alpha=0.20,
    pair_boost_beta=0.35,
    seed=20251213,
    recency_tau=8.0,
    recency_gamma=3.0,
    ban_last_m=0,
):
    rng = random.Random(seed)

    if not rows:
        raise ValueError("CSV에 데이터가 없습니다.")

    recent = rows[-window:] if len(rows) > window else rows
    draws = [d for d, _ in recent]
    max_draw = draws[-1]

    banned = set()
    if ban_last_m and ban_last_m > 0:
        for _, nums in rows[-ban_last_m:]:
            banned.update(nums)

    # 1) 시계열 가중치
    time_w = []
    for d in draws:
        age = max_draw - d
        w = 2.0 ** (-(age) / float(decay_half_life))
        time_w.append(w)

    # 2) 번호별 가중 빈도 + 마지막 출현
    freq = [0.0] * (N_MAX + 1)
    last_seen = [None] * (N_MAX + 1)

    for (w, (d, nums)) in zip(time_w, recent):
        for x in nums:
            freq[x] += w
            last_seen[x] = d

    # 3) 미출현 보너스
    gap_bonus = [0.0] * (N_MAX + 1)
    for x in range(1, N_MAX + 1):
        gap = max_draw if last_seen[x] is None else (max_draw - last_seen[x])
        gap_bonus[x] = math.log(1.0 + gap)

    # 3.5) 최근 출현 페널티
    recency_factor = [1.0] * (N_MAX + 1)
    for x in range(1, N_MAX + 1):
        gap = max_draw if last_seen[x] is None else (max_draw - last_seen[x])
        base = 1.0 - math.exp(-gap / float(recency_tau))  # gap=0 -> 0
        recency_factor[x] = max(1e-12, base ** float(recency_gamma))

    # 4) base_score
    max_f = max(freq[1:]) if max(freq[1:]) > 0 else 1.0
    freq_norm = [f / max_f for f in freq]
    gb_max = max(gap_bonus[1:]) or 1.0

    base_score = [0.0] * (N_MAX + 1)
    for x in range(1, N_MAX + 1):
        if x in banned:
            base_score[x] = 1e-12
            continue

        base = freq_norm[x] + 0.15 * (gap_bonus[x] / gb_max)
        base *= (1.0 - cold_penalty_alpha * freq_norm[x])
        base *= recency_factor[x]
        base_score[x] = max(1e-12, base)

    # 5) pair 보정
    pair_count = defaultdict(float)
    for w, (_, nums) in zip(time_w, recent):
        s = sorted(nums)
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                pair_count[(s[i], s[j])] += w

    # 6) 1차 추출 -> 2차(페어 부스트)
    items = list(range(1, N_MAX + 1))

    weights1 = [base_score[i] for i in items]
    first_pick = weighted_sample_without_replacement(items, weights1, K, rng)

    boosted = base_score[:]
    for x in range(1, N_MAX + 1):
        if x in banned:
            boosted[x] = 1e-12
            continue

        boost = 0.0
        for a in first_pick:
            i, j = (a, x) if a < x else (x, a)
            if i != j:
                boost += pair_count.get((i, j), 0.0)

        boosted[x] = max(1e-12, base_score[x] * (1.0 + pair_boost_beta * boost))

    weights2 = [boosted[i] for i in items]
    final_pick = weighted_sample_without_replacement(items, weights2, K, rng)
    final_pick.sort()

    return first_pick, final_pick, base_score, boosted, banned


def normalize_scores(scores):
    s = sum(scores[1:])
    if s <= 0:
        return [0.0] * len(scores)
    return [v / s for v in scores]


def print_ranked(scores, top_n=45, title="Rank"):
    """
    중복 방지 검증 + 블록 식별자 출력 포함
    """
    # 1) 원소 생성: 번호는 1..45 유일해야 함
    ranked = [(i, float(scores[i])) for i in range(1, N_MAX + 1)]
    nums = [n for n, _ in ranked]
    assert len(nums) == len(set(nums)), "버그: ranked에 중복 번호가 들어갔습니다."

    # 2) 정렬
    ranked.sort(key=lambda x: x[1], reverse=True)

    # 3) 출력(블록 구분선)
    print("\n" + "=" * 70)
    print(f"[{title}] (Top {top_n})")
    print("=" * 70)

    for rank, (num, val) in enumerate(ranked[:top_n], start=1):
        print(f"{rank:2d}. {num:2d}  {val:.8f}")


def main():
    csv_path = Path(__file__).resolve().parent / "nums.csv"
    rows = read_nums_csv(csv_path)

    first, final, base_score, boosted_score, banned = recommend_next_numbers(
        rows,
        window=250,
        decay_half_life=90.0,
        cold_penalty_alpha=0.20,
        pair_boost_beta=0.35,
        seed=20251122,
        recency_tau=8.0,
        recency_gamma=3.0,
        ban_last_m=0,
    )

    print(f"데이터 회차 범위: {rows[0][0]} ~ {rows[-1][0]} (총 {len(rows)}회)")
    if banned:
        print(f"하드컷(ban_last_m) 적용 번호: {sorted(banned)}")

    base_prob = normalize_scores(base_score)
    boosted_prob = normalize_scores(boosted_score)

    # 두 블록이 섞여 보이지 않게 구분선을 크게 출력
    print_ranked(base_prob, top_n=45, title="Base Probability (페어 보정 전)")
    print_ranked(boosted_prob, top_n=45, title="Boosted Probability (페어 보정 후)")

    print("\n1차 샘플(베이스):", first)
    print("최종 추천(최근회피+페어보정):", final)
    


if __name__ == "__main__":
    main()
