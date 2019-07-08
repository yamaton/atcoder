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
  int L, R;
  cin >> L >> R;

  if (R - L >= 2019) {
    cout << 0 << endl;
    return 0;
  }

  L %= 2019;
  R %= 2019;
  if (L > R) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 2020;
  for (int i = L; i < R; ++i) {
    for (int j = i + 1; j <= R; ++j) {
      int x = (i * j) % 2019;
      ans = min(ans, x);
    }
  }

  cout << ans << endl;

  return 0;
}
