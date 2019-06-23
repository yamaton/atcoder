import fractions


def cnt(A, B, d):
    return B // d - (A - 1) // d


A, B, C, D = map(int, input().split())
E = C // fractions.gcd(C, D) * D
res = (B - A + 1) - cnt(A, B, C) - cnt(A, B, D) + cnt(A, B, E)
print(res)
