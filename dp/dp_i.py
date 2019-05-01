"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_i

I - Coins

"""
import collections


def solve(ps):
    dp = collections.defaultdict(float)
    dp[0] = 1.0
    for p_i in ps:
        for head_count in reversed(range(N + 1)):
            dp[head_count] = p_i * dp[head_count - 1] + (1 - p_i) * dp[head_count]

    more_than_half = (N + 2) // 2
    res = sum(dp[head_count] for head_count in range(more_than_half, N + 1))
    return res


# def solve(ps):
#     dp = collections.defaultdict(float)
#     dp[0, 0] = 1.0
#     for i, p_i in enumerate(ps):
#         for head_count in reversed(range(N + 1)):
#             dp[i + 1, head_count] = p_i * dp[i, head_count - 1] + (1 - p_i) * dp[i, head_count]

#     print(dp)
#     more_than_half = (N + 2) // 2
#     res = sum(dp[N, head_count] for head_count in range(more_than_half, N + 1))
#     return res


N = int(input())
ps = [float(s) for s in input().split()]
res = solve(ps)
print(res)
