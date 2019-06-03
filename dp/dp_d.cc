#include <iostream>
using namespace std;

int N, W;
long long dp[100005];

int main() {
    cin >> N >> W;

    int w, v;
    for (int i = 1; i <= N; ++i) {
        cin >> w >> v;
        for (int x = W; x >= 0; --x) {
            if (x - w >= 0)
                dp[x] = max(dp[x], dp[x - w] + v);
        }
    }

    long long ans = 0LL;
    for (int x = 0; x <= W; ++x) {
        ans = max(ans, dp[x]);
    }
    cout << ans << endl;

}