"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_l

L - Deque
"""
import collections

def solve(xs):
    dp = collections.defaultdict(bool)
    dp[0] = 0
    for j in range(1, N + 1):
        dp[j] = - max(dp[])
    return dp[N]

N = int(input())
xs = [int(s) for s in input().split()]
assert len(xs) == N
res = solve(xs)
print(res)
