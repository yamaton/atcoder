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
#define DEBUG(x) cerr << (#x) << ": " << (x) << endl
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
    int p = N / 2;
    vl A(N);
    ll total = 0LL;

    REP(i, N) {
        cin >> A[i];
        total += A[i];
    }

    ll core_even = 0LL;
    for (int i = 0; i <= 2 * p; i += 2) core_even += A[i];
    ll core_odd = 0LL;
    for (int i = 1; i <= 2 * p + 1; i += 2) core_odd += A[i % N];
    
    vl ans(N);
    REP(i, N) {
        int new_idx = (2 * p + i) % N;
        if (i >= 2 and i % 2 == 0) core_even += A[new_idx] - A[i - 2];
        if (i >= 3 and i % 2 == 1) core_odd += A[new_idx] - A[i - 2];
        if (i % 2 == 0) ans[i] = 2 * core_even - total;
        if (i % 2 == 1) ans[i] = 2 * core_odd - total;
    }
    
    REP(i, N) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
