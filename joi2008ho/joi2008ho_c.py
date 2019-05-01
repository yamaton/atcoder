"""
Dart
https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c
"""
import bisect

def binary_search(arr, key):
    def is_ok(index):
        return arr[index] <= key

    ok = -1
    ng = len(arr)

    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if is_ok(mid):
            ok = mid
        else:
            ng = mid
    return ok


def solve(p):
    xs = [
        p[i] + p[j]
        for i in range(N + 1)
        for j in range(i, N + 1)
        if p[i] + p[j] <= M
    ]
    xs.sort()
    res = -100
    for x in xs:
        idx = binary_search(xs, M - x)
        # idx = bisect.bisect_right(xs, M - x) - 1
        total = xs[idx] + x
        if res < total:
            res = total

    print("xs:", xs)
    return res


N, M = map(int, input().split())
ps = [int(input()) for _ in range(N)]
ps.append(0)

res = solve(ps)
print(res)
