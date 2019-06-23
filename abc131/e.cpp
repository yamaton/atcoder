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

int main()
{
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    ll ub = (N - 1) * (N - 2) / 2;
    if (K > ub)
    {
        cout << "-1" << endl;
        return 0;
    }

    vector<pll> ans;
    for (int i = 1; i <= N - 1; ++i)
    {
        ans.emplace_back(i, N);
    }

    ll rest = ub - K;
    vector<pll> stock;
    for (int i = 1; i <= N - 1; ++i)
        for (int j = i + 1; j <= N - 1; ++j)
            stock.emplace_back(i, j);

    REP(i, rest)
    {
        ans.push_back(stock[i]);
    }

    cout << ans.size() << endl;
    for (auto &p : ans)
        cout << p.first << " " << p.second << endl;
    return 0;
}
