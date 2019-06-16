#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
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
#define DEBUG_VEC(v)                \
    cerr << #v << ": ";             \
    REP(__i, (v).size())            \
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
    int N, X;
    cin >> N >> X;
    vi L(N);
    REP(i, N) cin >> L[i];
    partial_sum(L.begin(), L.end(), L.begin());

    int res = 1;
    for (auto l: L) {
        if (l <= X) res++;
        else break;
    }

    cout << res << endl;
    return 0;
}
