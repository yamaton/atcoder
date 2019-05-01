"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_k

K - Stones
"""
import collections

def solve(xs):
    dp = collections.defaultdict(bool)

    dp[0] = False
    for j in range(1, K + 1):
            dp[j] = any(not dp[j - x] for x in xs if j >= x)
    return dp[K]

N, K = map(int, input().split())
choices = [int(s) for s in input().split()]
assert len(choices) == N
res = solve(choices)
print("First" if res else "Second")
