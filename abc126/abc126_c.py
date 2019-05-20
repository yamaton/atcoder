# https://atcoder.jp/contests/abc126_c

N, K = map(int, input().split())


def get_count(initial):
    cnt = 0
    point = initial
    while point < K:
        cnt += 1
        point *= 2
    return cnt


p = sum((1 / N) * 0.5 ** get_count(initial) for initial in range(1, N + 1))
print(p)
