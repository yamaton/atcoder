# https://atcoder.jp/contests/abc127_c
# Prison

N, M = map(int, input().split())
pairs = [[int(c) for c in input().split()] for _ in range(M)]
left = max(pair[0] for pair in pairs)
right = min(pair[1] for pair in pairs)
print(max(0, right - left + 1))
