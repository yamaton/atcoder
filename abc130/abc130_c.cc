#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
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
    ll W, H, x, y;
    cin >> W >> H >> x >> y;

    double area = (double) W * H / 2;
    int dup = (2 * x == W and 2 * y == H);
    cout << area << " " << dup << endl;
    return 0;
}
