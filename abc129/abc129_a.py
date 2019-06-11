P, Q, R = map(int, input().split())
res = sum(sorted([P, Q, R])[:2])
print(res)
