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

vi adj_list[100003];

int main() {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;

  REP(i, M) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
  }

  int S, T;
  cin >> S >> T;

  int ans = -1;
  vector<bool> seen(N + 1);
  deque<pair<int, int>> q;
  q.push_back(make_pair(S, 0));

  while (!q.empty()) {
    auto t = q.front();
    int curr = t.first;
    int time = t.second;
    q.pop_front();

    if (time % 3 == 0) {
      if (curr == T) {
        ans = time / 3;
        break;
      }
      seen[curr] = true;
    }

    for (auto v : adj_list[curr]) {
      if ((time + 1) % 3 != 0 or !seen[v]) {
        q.push_back(make_pair(v, time + 1));
      }
    }
  }

  cout << ans << endl;

  return 0;
}
