N = int(input())
pairs = [[int(s) for s in input().split()] for _ in range(N)]
pairs.sort(key=lambda tup: tup[1])

acc = 0
for (a, b) in pairs:
    acc += a
    if acc > b:
        print("No")
        break
else:
    print("Yes")

