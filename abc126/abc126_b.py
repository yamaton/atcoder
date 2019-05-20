# https://atcoder.jp/contests/abc126_b
# YYMM or MMYY


def is_month(n):
    return 1 <= n <= 12


S = input().strip()
n_upper = int(S[:2])
n_lower = int(S[2:])

if is_month(n_upper) and is_month(n_lower):
    print("AMBIGUOUS")
elif is_month(n_upper):
    print("MMYY")
elif is_month(n_lower):
    print("YYMM")
else:
    print("NA")
