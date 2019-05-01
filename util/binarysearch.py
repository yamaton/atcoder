"""
Meguru-shiki binary search
https://qiita.com/drken/items/97e37dd6143e33a64c8c
"""


def binary_search(seq, key):
    def is_ok(index):
        return seq[index] >= key

    ng = -1
    ok = len(seq)

    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if is_ok(mid):
            ok = mid
        else:
            ng = mid
    return ok


def test_bineary_search():
    xs = [1, 14, 32, 51, 51, 51, 243, 419, 750, 910]
    assert binary_search(xs, 51) == 3
    assert binary_search(xs, 1) == 0
    assert binary_search(xs, 910) == 9
    assert binary_search(xs, 52) == 6
    assert binary_search(xs, 0) == 0
    assert binary_search(xs, 911) == 10
