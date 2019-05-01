"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_e

E - Knapsack 2

value scatters less than weight does
"""
MAX_VALUE_SUM = 100000
DEFAULT_WEIGHT = 100000000007

def solve(wv_pairs):
    dp = [DEFAULT_WEIGHT] * (MAX_VALUE_SUM + 1)
    dp[0] = 0
    for i in range(N):
        w_i, v_i = wv_pairs[i]
        for vv in reversed(range(v_i, MAX_VALUE_SUM + 1)):
            dp[vv] = min(dp[vv], dp[vv - v_i] + w_i)
    return next(vv for vv in reversed(range(MAX_VALUE_SUM + 1)) if dp[vv] <= W)


N, W = map(int, input().split())
pairs = [[int(s) for s in input().split()] for _ in range(N)]
res = solve(pairs)
print(res)
