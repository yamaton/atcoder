# https://atcoder.jp/contests/abc126_d
import collections


N = int(input())
triples = [tuple(map(int, input().split())) for _ in range(N - 1)]

connected = collections.defaultdict(list)
for (a, b, _) in triples:
    connected[a].append(b)
    connected[b].append(a)

dist = dict()
for (u, v, d) in triples:
    dist[u, v] = d
    dist[v, u] = d

ini, _, _ = triples[0]
stack = [ini]
color = dict()
color[ini] = False

while stack:
    state = stack.pop()
    for new_state in connected[state]:
        if new_state not in color:
            d = dist[state, new_state]
            color[new_state] = color[state] if d % 2 == 0 else (not color[state])
            stack.append(new_state)


for i in sorted(color):
    print(int(color[i]))
