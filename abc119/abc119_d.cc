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

template <typename T>
int binary_search(std::vector<T>& seq, T key)
{
    auto is_ok = [&](int index) { return seq[index] >= key; };
    int ng = -1;
    int ok = seq.size();

    while (std::abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (is_ok(mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

ll dist(ll x, vl& s, vl& t, int offset1, int offset2) {
    ll dist = 0LL;
    int idx1 = binary_search(s, x);
    idx1 += offset1;
    ll first = s[idx1];
        if (idx1 >= s.size() or idx1 < 0) return 1e12;
    dist += abs(x - first);
    int idx2 = binary_search(t, first);
    idx2 += offset2;
        if (idx2 >= t.size() or idx2 < 0) return 1e12;
    dist += abs(t[idx2] - first);
    return dist;        
}

int main()
{
    ios::sync_with_stdio(false);

    ll A, B, Q;
    cin >> A >> B >> Q;
    vl s(A); REP(i, A) cin >> s[i];
    vl t(B); REP(i, B) cin >> t[i];

    REP(i, Q) {
        ll x;
        cin >> x;
        ll ans = 1e12;
        ans = min(ans, dist(x, s, t, 0, 0));
        ans = min(ans, dist(x, s, t, 0, -1));
        ans = min(ans, dist(x, s, t, -1, 0));
        ans = min(ans, dist(x, s, t, -1, -1));
        ans = min(ans, dist(x, t, s, 0, 0));
        ans = min(ans, dist(x, t, s, 0, -1));
        ans = min(ans, dist(x, t, s, -1, 0));
        ans = min(ans, dist(x, t, s, -1, -1));
        cout << ans << endl;
    }



    return 0;
}
