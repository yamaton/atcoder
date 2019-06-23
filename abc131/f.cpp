/* 
ABC 131 F - Must Be Rectangular!
https://atcoder.jp/contests/abc131/tasks/abc131_f

Nice problem utilizing mapping of (x, y) grid points and a bipartite graph
The code is based on the "AtCoder Live" Youtube channel analysis.

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

const int MAX_V = 1e5 + 5;
vi from[MAX_V * 2];
vector<bool> seen(MAX_V * 2);
vi cnt(2);

void dfs(int u)
{
    if (seen[u])
        return;
    seen[u] = true;
    cnt[u / MAX_V]++;

    for (auto &v : from[u])
        dfs(v);
}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    REP(i, N)
    {
        int x, y;
        cin >> x >> y;
        y += MAX_V;
        from[x].push_back(y);
        from[y].push_back(x);
    }

    ll ans = 0LL;
    REP(i, MAX_V * 2) {
        cnt = vi(2);
        dfs(i);
        ans += (ll) cnt[0] * cnt[1];
    }
    ans -= N;
    cout << ans << endl;

    return 0;
}
