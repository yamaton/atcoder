# import numpy as np
# [NOTE] Gets TLE in some cases even with Pypy3


def _gen_f(line):
    acc = 0
    for c in line:
        if c == "#":
            for _ in range(acc):
                yield acc
            yield 0
            acc = 0
        else:
            acc += 1

    for _ in range(acc):
        yield acc


def f(line):
    return list(_gen_f(line))


H, W = map(int, input().split())
grid = [list(input().strip()) for _ in range(H)]


row_wise = list(map(f, grid))
col_wise = list(zip(*map(f, zip(*grid))))

ans = 0
for i in range(H):
    for j in range(W):
        ans = max(ans, row_wise[i][j] + col_wise[i][j] - 1)

# row_wise = np.apply_along_axis(f, 0, grid)
# col_wise = np.apply_along_axis(f, 1, grid)

# for row in grid:
#     print("".join(row))
# print()
# print(row_wise)
# print()
# print(col_wise)
# print()

# ans = (row_wise + col_wise).max() - 1
print(ans)
