"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_b

B - Frog 2
"""
INF = 100000007
import collections

def cost(i, j):
    if i < 0:
        return INF
    return abs(hs[i] - hs[j])

def solve(hs):
    dp = collections.defaultdict(lambda: INF)
    dp[0] = 0
    for i in range(1, N):
        dp[i] = min(
            dp[i - kk] + cost(i - kk, i)
            for kk in range(1, K + 1)
        )
    return dp[N - 1]

N, K = map(int, input().split())
hs = [int(s) for s in input().split()]
assert len(hs) == N
res = solve(hs)
print(res)
