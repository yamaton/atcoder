# https://abc076.contest.atcoder.jp/tasks/abc076_c
#

S = input()
T = input()

candidates = []
for i in range(len(S) - len(T) + 1):
    yn = all(S[i + k] == "?" or S[i + k] == T[k] for k in range(len(T)))
    if yn:
        s = S[:i] + T + S[i + len(T) :]
        candidates.append(s)

if candidates:
    candidates = ["".join("a" if c == "?" else c for c in s) for s in candidates]
    print(min(candidates))
else:
    print("UNRESTORABLE")
