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
#include <deque>
#include <stack>
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

int main()
{
    ios::sync_with_stdio(false);
    int N, M, C;
    cin >> N >> M >> C;
    vi B(M); REP(i, M) cin >> B[i];
    int ans = 0;

    REP(i, N) {
        vi A(M); REP(i, M) cin >> A[i];
        int tmp = C;
        REP(i, M) {
            tmp += A[i] * B[i];
        }
        if (tmp > 0) ans++;
    }

    cout << ans << endl;
    
    return 0;
}
