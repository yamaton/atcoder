# https://atcoder.jp/contests/abc079/tasks/abc079_c

import sys
import itertools as it
import operator

if __name__ == "__main__":
    xs = [int(c) for c in input().strip()]
    ops = it.product([-1, 1], repeat=3)
    res = next(op for op in ops if 7 == (xs[0] + sum(map(operator.mul, xs[1:], op))))
    symbols = ["+" if i == 1 else "-" for i in res]
    iterable = filter(
        lambda x: x is not None,
        it.chain.from_iterable(
            it.zip_longest(map(str, xs), symbols)
        )
    )
    res = "".join(iterable) + "=7"
    print(res)
