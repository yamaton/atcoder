"""
AtCoder
    :author: vierbein
"""
from __future__ import absolute_import, division, print_function

import sys


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


s = input()
set_chars = set(s)
if len(set_chars) == 2 and all(s.count(i) == 2 for i in set_chars):
    print("Yes")
else:
    print("No")
