"""
AtCoder
    :author: vierbein
"""
from __future__ import absolute_import, division, print_function

# import itertools as it
# import collections
import sys


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def main():
    N = int(input())
    xs = [int(s) for s in input().split()]
    h_prev = 100000000000
    res = True
    for h in reversed(xs):
        if h - h_prev > 1:
            res = False
            break
        elif h == h_prev + 1:
            h_prev = h - 1
        else:
            h_prev = h

    if res:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()