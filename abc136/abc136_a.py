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


A, B, C = map(int, input().split())
print(max(0, C - A + B))