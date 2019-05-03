# https://atcoder.jp/contests/kupc2015/tasks/kupc2015_a


def count(s):
    def helper(s, acc):
        pos = -1
        tokyo = s.find("oykot")
        kyoto = s.find("otoyk")

        if tokyo >= 0 and kyoto >= 0:
            pos = min(tokyo, kyoto)
        elif tokyo >= 0 and kyoto == -1:
            pos = tokyo
        elif tokyo == -1 and kyoto >= 0:
            pos = kyoto
        else:
            pos = -1

        if pos == -1:
            res = acc
        else:
            res = helper(s[pos + 5 :], acc + 1)
        return res

    return helper(s, 0)


N = int(input())
ss = ["".join(reversed(input())) for _ in range(N)]
for s in ss:
    print(count(s))
