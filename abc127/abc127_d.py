# https://atcoder.jp/contests/abc127/tasks/abc127_d
import itertools as it

N, M = map(int, input().split())
A = [int(s) for s in input().split()]
A.sort()

pairs = [tuple(int(s) for s in input().split()) for _ in range(M)]
pairs.sort(key=lambda tup: tup[1], reverse=True)

iterable = it.chain.from_iterable([it.repeat(v, times=count) for (count, v) in pairs])
# print(list(iterable))

res = sum(A)
for (old, new_) in zip(A, iterable):
    if old <= new_:
        res += new_ - old
    else:
        break

print(res)
