

N = int(input())
p = N // 2
A = [int(s) for s in input().split()]
assert len(A) == N
total = sum(A)

ans = [0] * N
core_even = sum(A[i] for i in range(0, N + 1, 2))
core_odd = sum(A[i % N] for i in range(1, N + 1, 2))

for i in range(N):
    new_idx = (2 * p + i) % N
    if i >= 2 and i % 2 == 0:
        core_even += A[new_idx] - A[i - 2]
    if i >= 3 and i % 2 == 1:
        core_odd += A[new_idx] - A[i - 2]

    if i % 2 == 0:
        ans[i] = 2 * core_even - total
    else:
        ans[i] = 2 * core_odd - total

print(*ans)