import bisect
import itertools as it

N, K = map(int, input().split())
a = [int(s) for s in input().split()]
a = [0] + list(it.accumulate(a))

cnt = 0
for i in range(N):
    j = bisect.bisect_left(a, K + a[i])
    cnt += N - j + 1

print(cnt)
