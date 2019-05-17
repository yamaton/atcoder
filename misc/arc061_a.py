# https://arc061.contest.atcoder.jp/tasks/arc061_a

import sys
import itertools as it

sys.setrecursionlimit(2000)


def solve(s, i):
    if s == "":
        yield 0
    elif i == len(s):
        yield int(s)
    else:
        for x in solve(s[i:], 1):
            yield x + int(s[:i])
        yield from solve(s, i + 1)


S = input().strip()
res = sum(solve(S, 1))
print(res)
