# https://atcoder.jp/contests/abc104/tasks/abc104_c

import itertools as it

INF = 100000007

if __name__ == "__main__":
    D, G = map(int, input().split())
    pairs = [[int(s) for s in input().split()] for _ in range(D)]
    p, c = zip(*pairs)
    res = INF

    iterables = it.product([False, True], repeat=D)
    for choice in iterables:
        cnt = 0
        total = 0
        for i in range(D):
            if choice[i]:
                cnt += p[i]
                total += 100 * (i + 1) * p[i] + c[i]

        for j in reversed(range(D)):
            if total >= G:
                break
            if not choice[j]:
                item_value = 100 * (j + 1)
                item_count = min(p[j], (G - total + item_value - 1) // item_value)
                cnt += item_count
                total += item_value * item_count

        if cnt < res:
            res = cnt

    print(res)
