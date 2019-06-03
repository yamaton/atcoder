"""
AtCoder Educational DP Contest
https://atcoder.jp/contests/dp/tasks/dp_f

F - LCS

"""
MAX_VALUE_SUM = 100000
DEFAULT_WEIGHT = 100000000007

import collections
import itertools as it


def solve(s, t):
    dp = collections.defaultdict(list)
    for i, cs in enumerate(s):
        for j, ct in enumerate(t):
            if cs == ct:
                dp[i + 1, j + 1] = dp[i, j] + [cs]
            else:
                dp[i + 1, j + 1] = max(dp[i, j + 1], dp[i + 1, j], key=len)

    iterable = dp[len(s), len(t)]
    return "".join(iterable)


def solve2(s, t):
    dp = collections.defaultdict(int)
    for i, cs in enumerate(s):
        for j, ct in enumerate(t):
            if cs == ct:
                dp[i + 1, j + 1] = dp[i, j] + 1
            else:
                dp[i + 1, j + 1] = max(dp[i, j + 1], dp[i + 1, j])

    # from uwi's implementation
    i, j = len(s), len(t)
    res = collections.deque()
    while i >= 0 and j >= 0:
        if s[i - 1] == t[j - 1]:
            res.appendleft(s[i - 1])
            i -= 1
            j -= 1
        elif dp[i, j] == dp[i - 1, j]:
            i -= 1
        else:
            j -= 1

    return "".join(res)


seq1 = input().strip()
seq2 = input().strip()
res = solve2(seq1, seq2)
print(res)

