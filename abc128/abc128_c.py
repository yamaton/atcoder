# https://atcoder.jp/contests/abc128/abc128_c
import itertools as it

N, M = map(int, input().split())
xss = [[int(s) for s in input().split()][1:] for _ in range(M)]
ps = [int(s) for s in input().split()]

iterable = it.product([0, 1], repeat=N)
cnt = 0
for switches in iterable:
    res = True
    for xs, p in zip(xss, ps):
        selected = [switches[x - 1] for x in xs]
        is_on = (sum(selected) % 2) == p
        res = res and is_on

    if res:
        cnt += 1

print(cnt)
