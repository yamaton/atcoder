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
  int N, D;
  cin >> N >> D;

  vector<vi> points(N, vi(D));
  REP(i, N) REP(j, D) cin >> points[i][j];

  int cnt = 0;
  REP(i, N) {
    REP(j, i) {
      int dist2 = 0;
      REP(k, D) {
        int diff = points[i][k] - points[j][k];
        dist2 += diff * diff;
      }
      int d = (int)sqrt(dist2);
      if (d * d == dist2) cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}
