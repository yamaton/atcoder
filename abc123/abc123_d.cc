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
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vl a(x);
    vl b(y);
    vl c(z);
    REP(i, x) cin >> a[i];
    REP(i, y) cin >> b[i];
    REP(i, z) cin >> c[i];

    priority_queue<ll> q;
    for (auto aa: a) {
        for (auto bb: b) {
            q.push(aa + bb);
        }
    }

    priority_queue<ll> q2;
    int cnt = 0;
    while (!q.empty() and cnt < k) {
        ll ab = q.top();
        q.pop();
        cnt++;
        for (auto cc: c) {
            q2.push(ab + cc);
        }
    }

    REP(i, k) {
        ll ans = q2.top();
        q2.pop();
        cout << ans << endl;
    }

    return 0;
}
