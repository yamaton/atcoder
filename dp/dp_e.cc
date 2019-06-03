#include <iostream>
using namespace std;

constexpr long long INF = 10000000007LL;
int N, W;
long long dp[100005];

int main() {
    cin >> N >> W;

    dp[0] = 0LL;
    for (int x = 1; x <= 100*1000; ++x)
        dp[x] = INF;

    int w, v;
    for (int i = 1; i <= N; ++i) {
        cin >> w >> v;
        for (int x = 100*1000; x >= 0; --x) {
            if (x - v >= 0)
                dp[x] = min(dp[x], dp[x - v] + w);
        }
    }

    long long ans = 0LL;
    for (int x = 100*1000; x >= 0; --x) {
        if (dp[x] <= W) {
            ans = x;
            break;
        }
    }
    cout << ans << endl;

}