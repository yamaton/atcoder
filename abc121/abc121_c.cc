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
    int N, M;
    cin >> N >> M;

    vector<pll> pairs;
    REP(i, N) {
        int A, B;
        cin >> A >> B;
        pairs.emplace_back(A, B);
    }
    sort(pairs.begin(), pairs.end());

    ll ans = 0LL;
    int cnt = 0;
    REP(i, N) {
        auto p = pairs[i];
        for (int j = 0; j < p.second; j++) {
            ans += p.first;
            cnt ++;

            if (cnt == M) {
                cout << ans << endl;
                return 0;
            }
        }
    }
}
