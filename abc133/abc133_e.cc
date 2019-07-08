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

const ll BIGINT = 1e9 + 7;

ll permutations(ll n, ll k) {
  if (n < k or k < 0) return 0LL;

  ll ans = 1LL;
  REP(i, k) {
    ans = (ans * n) % BIGINT;
    n--;
  }
  return ans;
}

ll dfs(const int K, const vector<vector<int>>& adj_list, const int now,
       const int from) {
  ll nn = (from == -1) ? K - 1 : K - 2;
  ll kk = (from == -1) ? adj_list[now].size() : adj_list[now].size() - 1;

  ll ans = permutations(nn, kk);
  for (auto& v : adj_list[now]) {
    if (v != from) {
      ans *= dfs(K, adj_list, v, now);
      ans %= BIGINT;
      kk--;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<vi> adj_list(N + 1);

  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }
  REP(ii, N + 1) { DEBUG_VEC(adj_list[ii]); }

  cout << dfs(K, adj_list, 1, -1) << endl;
  return 0;
}
