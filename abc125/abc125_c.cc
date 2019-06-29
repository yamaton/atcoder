/* 

A[0]  A[1]  A[2]   .... A[N-3]  A[N-2]  A[N-1]
<--------->             <-------------------->
    left(2)                  right(N-3)

left has index  0 .. N  (0 .. empty,  N .. full)
right has index 0 .. N  (0 .. full,   N .. empty)

*/

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
#define ALL(x) (x).begin(), (x).end()
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

ll gcd(ll x, ll y)
{
    if (x < y)
        std::swap(x, y);

    if (y == 0)
        return x;

    return gcd(y, x % y);
}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vi A(N);
    REP(i, N)
        cin >> A[i];

    vl lhs(N + 1);
    vl rhs(N + 1);

    for (int i = 0; i < N; ++i)
    {
        lhs[i + 1] = gcd(lhs[i], A[i]);
    }

    for (int i = N - 1; i >= 0; --i)
    {
        rhs[i] = gcd(rhs[i + 1], A[i]);
    }

    ll res = 0LL;
    for (int i = 0; i < N; ++i)
    {
        res = max(res, gcd(lhs[i], rhs[i + 1]));
    }
    cout << res << endl;
    return 0;
}
