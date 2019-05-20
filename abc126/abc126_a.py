# https://atcoder.jp/contests/abc126_a
# Changing a Character


N, K = map(int, input().split())
S = input().strip()
S_replaced = "".join(c.lower() if i == K else c for i, c in enumerate(S, start=1))
print(S_replaced)
