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

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi p(n);
    REP(i, n)
        cin >> p[i];
    int ans = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        if (min(p[i - 1], p[i + 1]) < p[i] and p[i] < max(p[i - 1], p[i + 1])) {
            ans++;
            // cerr << i << " " << p[i] << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
