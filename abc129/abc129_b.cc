#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main()
{
    int N;
    cin >> N;

    vi W(N);
    rep(i, N) cin >> W[i];

    partial_sum(W.begin(), W.end(), W.begin());
    int ans = 1e9;
    rep(i, W.size()) ans = min(ans, abs(W.back() - 2 * W[i]));
    cout << ans << endl;

    return 0;
}
