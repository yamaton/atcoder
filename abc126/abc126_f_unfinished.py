# https://atcoder.jp/contests/abc126_f
# [bug]

import itertools as it

M, K = map(int, input().split())
if K >= 2 ** M:
    res = -1
elif K == 0:
    iterable = it.chain.from_iterable(map(lambda x: it.repeat(x, 2), range(2 ** M)))
    res = " ".join(map(str, iterable))
else:
    s = " ".join(str(i) for i in range(2 ** M) if i != K)
    res = " ".join([str(K), s, str(K), "".join(reversed(s))])
print(res)
