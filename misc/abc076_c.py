# https://abc076.contest.atcoder.jp/tasks/abc076_c

S = input()
T = input()

s_rev = "".join(reversed(S))
t_rev = "".join(reversed(T))

found = False
for i in range(len(S) - len(T) + 1):
    yn = all(s_rev[i + k] == "?" or s_rev[i + k] == t_rev[k] for k in range(len(T)))
    if yn:
        s_rev = s_rev[:i] + t_rev + s_rev[i + len(T) :]
        found = True
        break

if found:
    s = "".join("a" if c == "?" else c for c in reversed(s_rev))
    print(s)
else:
    print("UNRESTORABLE")
