# # https://atcoder.jp/contests/abc128/abc128_b

N = int(input())
pairs = [input().split() for _ in range(N)]
pairs = [(a, int(b)) for a, b in pairs]
indices = list(range(N))
indices.sort(key=lambda idx: (pairs[idx][0], -pairs[idx][1]))
for idx in indices:
    print(idx + 1)

