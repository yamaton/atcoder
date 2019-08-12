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


def get_digits(n):
    res = 0
    while n > 0:
        res += 1
        n //= 10
    
    return res


N = int(input())
digits = get_digits(N)

if digits == 2:
    res = 9
elif digits == 4:
    res = 909
elif digits == 6:
    res = 90909
elif digits == 1:
    res = N
elif digits == 3:
    res = N - 99 + 9
elif digits == 5:
    res = N - 9999 + 909
else:
    res = -1

print(res)