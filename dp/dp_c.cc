#include <iostream>
using namespace std;

constexpr long long INF = 100000000007;

int N;
long long dp[100005][3];
int triple[100005][3];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> triple[i][0] >> triple[i][1] >> triple[i][2];
    }

    for (int k = 0; k < 3; ++k) {
        dp[0][k] = 0;
    }

    for (int i = 1; i <= N; ++i) {
        for (int k = 0; k < 3; ++k) {
            dp[i][k] = -INF;
            for (int kp = 0; kp < 3; ++kp) {
                if (k != kp)
                    dp[i][k] = max(dp[i][k], dp[i - 1][kp] + triple[i][k]);
            }
        }
    }

    long long ans = -INF;
    for (int k = 0; k < 3; ++k)
        ans = max(ans, dp[N][k]);
    cout << ans << endl;
}