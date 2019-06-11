import collections

BIGINT = int(1e9 + 7)

N, M = map(int, input().split())
invalid = {int(input()) for _ in range(M)}
dp = collections.defaultdict(int)
dp[0] = 1
for i in range(1, N + 1):
    if i in invalid:
        dp[i] = 0
    else:
        dp[i] = (dp[i - 1] + dp[i - 2]) % BIGINT

print(dp[N])
