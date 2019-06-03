#include <iostream>
using namespace std;

#define INF 1000000007;

int N, K;
int h[100005];
long long dp[100005];

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> h[i];
    }

    dp[1] = 0LL;
    for (int i = 2; i <= N; ++i) {
        dp[i] = INF;
        for (int kk = 1; kk <= K; ++kk) {
            if (i - kk >= 1) {
                dp[i] = min(dp[i], dp[i - kk] + abs(h[i] - h[i - kk]));
            }
        }
    }

    cout << dp[N] << endl;
}