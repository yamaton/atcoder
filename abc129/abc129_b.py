import itertools as it

N = int(input())
W = [int(s) for s in input().split()]
acc = list(it.accumulate([0] + W))
res = min([abs(acc[-1] - 2 * x) for x in acc])
print(res)
