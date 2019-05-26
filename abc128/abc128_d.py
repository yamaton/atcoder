# https://atcoder.jp/contests/abc128/abc128_d
import itertools as it

N, K = map(int, input().split())
vs = [int(s) for s in input().split()]

acc = [0] + list(it.accumulate(vs))
res = 1000000000
for left in range(min(N, K) + 1):
    for right in range(min(N, K) + 1 - left):
        tmp = acc[N - right] - acc[left]
        rem = K - left - right
        rest = sorted(vs[:left] + vs[N - right :])[:rem]

        for x in rest:
            if x < 0:
                tmp += x
        if tmp < res:
            res = tmp

print(acc[-1] - res)
