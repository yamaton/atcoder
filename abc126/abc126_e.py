# https://atcoder.jp/contests/abc126_e
import collections

N, M = map(int, input().split())
triples = [tuple(map(int, input().split())) for _ in range(M)]

connected = collections.defaultdict(list)
for (a, b, _) in triples:
    connected[a].append(b)
    connected[b].append(a)

nodes = set(range(1, N + 1))
seen = set()
cnt = 0

for i in nodes:
    if i not in seen:
        cnt += 1
        stack = [i]
        while stack:
            state = stack.pop()
            for new_state in connected[state]:
                if new_state not in seen:
                    seen.add(new_state)
                    stack.append(new_state)

print(cnt)
