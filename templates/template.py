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


N = int(input())
a, b = map(int, input().split())
xs = [int(s) for s in input().split()]
