"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_j

J - Sushi
"""
import collections

MAX_TRIALS = 500000

def solve(xs):
    dp = collections.defaultdict(float)
    dp[0, tuple(ps)] = 1.0
    for i in range(MAX_TRIALS):
        for sushi in range(N):

            dp[i + 1, ] = (1. / N) * sum(dp[i - 1, ])

    return res


N = int(input())
xs = [int(s) for s in input().split()])
res = solve(xs)
print(res)
