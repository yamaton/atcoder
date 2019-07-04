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

const ll BIGINT = 1e9 + 7;

// A?GC  AG?C  ACG   GAC  AGC
// index is ACGT order
ll dp[105][4][4][4];

int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  dp[N][3][3][3] = 1;  // "TTT"

  for (int idx = N - 1; idx >= 0; --idx) {
    REP(i, 4) REP(j, 4) REP(k, 4) REP(l, 4) {
      if (k == 0 and i == 2 and l == 1)  // A?GC
        dp[idx][l][i][j] = 0;
      else if (k == 0 and j == 2 and l == 1)  // AG?C
        dp[idx][l][i][j] = 0;
      else if (j == 0 and i == 1 and l == 2)  // ACG
        dp[idx][l][i][j] = 0;
      else if (j == 2 and i == 0 and l == 1)  // GAC
        dp[idx][l][i][j] = 0;
      else if (j == 0 and i == 2 and l == 1)  // AGC
        dp[idx][l][i][j] = 0;
      else {
        dp[idx][l][i][j] += dp[idx + 1][i][j][k];
        dp[idx][l][i][j] %= BIGINT;
      }
    }
  }
  ll ans = 0LL;
  REP(i, 4) REP(j, 4) REP(k, 4) {
    ans += dp[0][i][j][k];
    ans %= BIGINT;
  }
  cout << ans << endl;
  return 0;
}
