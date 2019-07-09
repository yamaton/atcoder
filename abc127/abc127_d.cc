#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<numeric>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define DEBUG(x) cerr << (#x) << ": " << (x) << endl
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;


int main() {
  int N, M; cin >> N >> M;
  vi A(N); REP(i, N) cin >> A[i];
  vector<pii> pairs;
  REP(i, M) {
    int b, c;
    cin >> b >> c;
    pairs.emplace_back(b, c);
  }
  sort(A.begin(), A.end());
  sort(pairs.begin(), pairs.end(), [](pii a, pii b){ return a.second > b.second; });

  bool done = false;
  int i = 0;
  for (auto& pair: pairs) {
    int b, c;
    tie(b, c) = pair;
    REP(k, b) {
      if (i < N and c >= A[i]) {
        A[i] = c;
        i++;
      } else {
        done = true;
        break;
      }
    }
    if(done) break;
  }

  ll ans = accumulate(A.begin(), A.end(), 0LL);
  cout << ans << endl;
  return 0;
}