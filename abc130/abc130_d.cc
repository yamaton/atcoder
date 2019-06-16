#include <algorithm>
#include <bitset>
#include <cassert>
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

vl a;

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

int main()
{
    ios::sync_with_stdio(false);
    int N;
    ll K;
    cin >> N >> K;
    a.resize(N + 1);
    REP(i, N)
        cin >> a[i + 1];
    partial_sum(a.begin(), a.end(), a.begin());

    ll res = 0;
    for (auto& x : a) {
        int j = binary_search(a, K + x);
        ll inc = N + 1 - j;
        res += inc;
    }

    cout << res << endl;

    return 0;
}
