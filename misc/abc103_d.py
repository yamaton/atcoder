# https://atcoder.jp/contests/abc103/tasks/abc103_d
import sys

def solve():
    pairs.sort(key=lambda pair: pair[1])
    cnt = 0
    base = 0
    for (a, b) in pairs:
        if a >= base:
            cnt += 1
            base = b
    return cnt

n, m = map(int, input().split())
pairs = [tuple(int(c) for c in input().split()) for _ in range(m)]
print(n, pairs, file=sys.stderr)
print(solve())