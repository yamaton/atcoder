// K ln (K) implementation in getting top K of elements from
// cartesian product of three arrays X Y Z
//

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
#define DEBUG_VEC(v)          \
  cerr << #v << ": ";         \
  REP(__i, (v).size())        \
  cerr << ((v)[__i]) << ", "; \
  cerr << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
  ios::sync_with_stdio(false);
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vl a(x);
  vl b(y);
  vl c(z);
  REP(i, x) cin >> a[i];
  REP(i, y) cin >> b[i];
  REP(i, z) cin >> c[i];
  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());
  sort(c.begin(), c.end(), greater<ll>());
  priority_queue<tuple<ll, ll, ll, ll>> q;
  set<tuple<ll, ll, ll>> seen;

  q.push(make_tuple(a[0] + b[0] + c[0], 0, 0, 0));
  seen.insert(make_tuple(0, 0, 0));

  ll ans = 0LL;
  REP(p, k) {
    ll v, i, j, k;
    tie(v, i, j, k) = q.top();
    cout << v << endl;
    q.pop();
    tuple<ll, ll, ll> t;

    t = make_tuple(i + 1, j, k);
    if (seen.find(t) == seen.end() and i + 1 < x) {
      seen.insert(t);
      q.push(make_tuple(a[i + 1] + b[j] + c[k], i + 1, j, k));
    }

    t = make_tuple(i, j + 1, k);
    if (seen.find(t) == seen.end() and j + 1 < y) {
      seen.insert(t);
      q.push(make_tuple(a[i] + b[j + 1] + c[k], i, j + 1, k));
    }

    t = make_tuple(i, j, k + 1);
    if (seen.find(t) == seen.end() and k + 1 < z) {
      seen.insert(t);
      q.push(make_tuple(a[i] + b[j] + c[k + 1], i, j, k + 1));
    }
  }

  return 0;
}
