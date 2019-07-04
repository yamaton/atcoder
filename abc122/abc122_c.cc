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
#include <stack>
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
  int N, Q;
  cin >> N >> Q;

  string s;
  cin >> s;

  vi acc(N + 1);
  for (int i = 1; i < N; ++i) {
    acc[i + 1] = acc[i];
    if (s[i - 1] == 'A' and s[i] == 'C') acc[i + 1]++;
  }

  // DEBUG_VEC(acc);

  int l, r;
  REP(i, Q) {
    cin >> l >> r;
    // acc[l - 1] because beginning letter is at the index (l - 1)
    //    and the last of the initial two letter set is at l

    // 0 1 2 3 4 5
    //  A C C G T
    //  1 2 3 4 5
    int res = acc[r] - acc[l];

    cout << res << endl;
  }
  return 0;
}
