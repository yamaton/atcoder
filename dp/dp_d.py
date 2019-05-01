"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_d

D - Knapsack 1
"""

def solve(wv_pairs):
    dp = [0] * (W + 1)
    for i in range(N):
        w_i, v_i = wv_pairs[i]
        for ww in range(W, w_i - 1, -1):
            dp[ww] = max(dp[ww], dp[ww - w_i] + v_i)
    return max(dp)


N, W = map(int, input().split())
pairs = [[int(s) for s in input().split()] for _ in range(N)]
res = solve(pairs)
print(res)
