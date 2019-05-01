"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_h

H - Grid

"""
import collections

DIVISOR = 1000000007

def solve(grid):
    dp = collections.defaultdict(int)
    dp[0, 0] = 1

    for hh in range(H):
        for ww in range(W):
            if (hh, ww) == (0, 0):
                continue
            if grid[hh][ww] == "#":
                dp[hh, ww] = 0
            else:
                dp[hh, ww] = (dp[hh - 1, ww] + dp[hh, ww - 1]) % DIVISOR
    return dp[H - 1, W - 1]


H, W = map(int, input().split())
grid = [input().strip() for _ in range(H)]
res = solve(grid)
print(res)
