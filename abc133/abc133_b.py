import math
import numpy as np

N, D = map(int, input().split())
xss = np.array([[int(s) for s in input().split()] for _ in range(N)])


cnt = 0
for i in range(N):
    for j in range(i):
        diff2 = ((xss[i] - xss[j])**2).sum()
        d = int(np.sqrt(diff2))
        if d * d == diff2: 
            cnt += 1

print(cnt)