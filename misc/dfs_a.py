# https://atc001.contest.atcoder.jp/tasks/dfs_a


H, W = map(int, input().split())
grid = [input().strip() for _ in range(H)]

for i in range(H):
    for k in range(W):
        if grid[i][k] == "s":
            start = (i, k)
        if grid[i][k] == "g":
            goal = (i, k)

stack = [start]
seen = {start}
while stack:
    (i, k) = stack.pop()
    if (i, k) == goal:
        print("Yes")
        break
    for (next_i, next_k) in [(i + 1, k), (i - 1, k), (i, k - 1), (i, k + 1)]:
        criteria = (
            0 <= next_i < H
            and 0 <= next_k < W
            and (next_i, next_k) not in seen
            and (grid[next_i][next_k] == "." or grid[next_i][next_k] == "g")
        )
        if criteria:
            seen.add((next_i, next_k))
            stack.append((next_i, next_k))
else:
    print("No")
