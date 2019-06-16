#include <iostream>
using namespace std;
const long long BIGINT = (long long)1e9 + 7;

long long pow(long long x, int n)
{
    long long res = 1LL;
    int acc = 1;
    for (int i = 0; acc <= n; ++i) {
        if ((n >> i) & 1) {
            res = (res * x) % BIGINT;
        }
        x = (x * x) % BIGINT;
        acc *= 2;
    }
    return res;
}

long long modinv(long long a, int p)
{
    return pow(a, p - 2);
}

long long binomial_coeff(int n, int r)
{
    if (n < r)
        return 0LL;
    if (2 * r > n)
        return binomial_coeff(n, n - r);

    long long numer = 1LL;
    long long denom = 1LL;
    int rr = r;
    for (int i = 0; i < rr; ++i) {
        numer = (numer * n) % BIGINT;
        denom = (denom * r) % BIGINT;
        n--;
        r--;
    }
    cerr << "  numer = " << numer << endl;
    cerr << "  denom = " << denom << endl;
    return (numer * modinv(denom, BIGINT)) % BIGINT;
}
