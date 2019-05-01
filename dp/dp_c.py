"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_c

C - Vacation
"""
INF = 100000007
import collections

def solve(troikas):
    dp = collections.defaultdict(lambda: -INF)
    for act in range(3):
        dp[(0, act)] = troikas[0][act]

    for i in range(1, N):
        for act in range(3):
            dp[(i, act)] = max(
                dp[(i - 1, prev_act)] + troikas[i][act]
                for prev_act in range(3)
                if prev_act != act
            )
    return max(dp[(N - 1, act)] for act in range(3))

N = int(input())
troikas = [[int(s) for s in input().split()] for _ in range(N)]
res = solve(troikas)
print(res)
