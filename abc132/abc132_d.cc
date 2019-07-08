#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define DEBUG(x) cout << (#x) << ": " << (x) << endl
#define DEBUG_VEC(v)            \
    cerr << #v << ": ";         \
    REP(__i, (v).size())        \
    cerr << ((v)[__i]) << ", "; \
    cerr << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll BIGINT = 1e9 + 7;

long long pow(ll x, ll n)
{
    ll res = 1LL;
    ll acc = 1LL;
    for (int i = 0; acc <= n; ++i)
    {
        if ((n >> i) & 1)
        {
            res = (res * x) % BIGINT;
        }
        x = (x * x) % BIGINT;
        acc *= 2;
    }
    return res;
}

long long modinv(ll a, ll p)
{
    return pow(a, p - 2);
}

long long binomial_coeff(ll n, ll r)
{
    if (2 * r > n)
        r = n - r;
    if (n < r or r < 0)
        return 0LL;

    long long numer = 1LL;
    long long denom = 1LL;
    const int rrr = (int)r;
    REP(i, rrr)
    {
        numer = (numer * n) % BIGINT;
        denom = (denom * r) % BIGINT;
        n--;
        r--;
    }
    return (numer * modinv(denom, BIGINT)) % BIGINT;
}


ll count(ll N, ll K, ll i)
{
    ll blue = binomial_coeff(K - i + (i - 1), i - 1);
    ll red = binomial_coeff((N - K) - (i - 1) + (i + 1 - 1), i);
    return (blue * red) % BIGINT;
}

int main()
{
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;

    for (int i = 1; i <= K; ++i)
    {
        cout << count(N, K, i) << endl;
    }

    return 0;
}
