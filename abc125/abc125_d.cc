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
    int N;
    cin >> N;
    vi A(N);
    REP(i, N) cin >> A[i];

    int neg_cnt = 0;
    ll total = 0LL;
    int smallest = 1e9 + 7;
    REP(i, N) {
        if (A[i] < 0) neg_cnt++;
        total += abs(A[i]);
        smallest = min(smallest, abs(A[i]));
    }

    if (neg_cnt % 2 > 0) {
        total -= 2 * smallest;
    }

    cout << total << endl;
    return 0;
}
