"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_a

A - Frog 1
"""
INF = 100000007

def cost(i, j):
    return abs(hs[i] - hs[j])

def solve(hs):
    dp = [INF] + [0] * n
    for i in range(2, n + 1):
        dp[i] = min(dp[i - 2] + cost(i - 2, i), dp[i - 1] + cost(i - 1, i))
    return dp[n]

n = int(input())
hs = [INF] + [int(s) for s in input().split()]
assert len(hs) == n + 1
res = solve(hs)
print(res)
