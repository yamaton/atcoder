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
#define DEBUG_VEC(v)            \
    cerr << #v << ": ";         \
    REP(__i, (v).size())        \
    cerr << ((v)[__i]) << ", "; \
    cerr << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<ll> vl;



int main()
{
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<pair<string, int>> pairs;
    REP(i, N) {
      string s; int p;
      cin >> s >> p;
      pairs.emplace_back(s, p);
    }

    vi idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){
      return make_pair(pairs[a].first, -pairs[a].second) < make_pair(pairs[b].first, -pairs[b].second);
    });

    REP(i, N) {
      cout << idx[i] + 1 << endl;
  }

    return 0;
}
