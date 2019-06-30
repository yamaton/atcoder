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

int f(int x) {
    return ((x + 9) /10) * 10;
}

int main()
{
    ios::sync_with_stdio(false);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int x = 10;
    vi xs {a, b, c, d, e};
    REP(i, 5) {
        int tmp = xs[i] % 10;
        if (tmp > 0) x = min(x, tmp);
    }
    x = 10 - x;
    cout << f(a) + f(b) + f(c) + f(d) + f(e) - x << endl;

    return 0;
}
