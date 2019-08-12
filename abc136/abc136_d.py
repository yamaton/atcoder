"""
AtCoder
    :author: vierbein
"""
from __future__ import absolute_import, division, print_function

import itertools as it
# import collections
import sys


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    S = input()
    counts = [sum(1 for _ in iterable) for _, iterable in it.groupby(S)]
    acc = list(it.accumulate(counts))
    res = [0] * len(S)
    i = 0
    while i < len(counts):
        rs = counts[i]
        ls = counts[i + 1]
        res[acc[i] - 1] = (rs + 1) // 2 + ls // 2
        res[acc[i]] = rs // 2 + (ls + 1) // 2
        i += 2
    print(*res)
        


if __name__ == "__main__":
    main()
