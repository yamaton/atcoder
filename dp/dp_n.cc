#include <iostream>
#include <map>
#include <vector>
using namespace std;

const long long INF = (1LL << 62);
int N;
long long dp[405][410];
long long acc[410];

int main()
{
    cin >> N;

    acc[0] = 0LL;
    for (int i = 1; i <= N; ++i) {
        cin >> acc[i];
        acc[i] += acc[i - 1];
    }

    for (int i = 0; i < N; ++i)
        dp[i][i + 1] = 0LL;

    for (int w = 2; w <= N; ++w) {
        for (int i = 0; i <= N - w; ++i) {
            int j = i + w;
            long long subcost = INF;
            for (int k = i + 1; k < j; ++k) {
                subcost = min(subcost, dp[i][k] + dp[k][j]);
            }
            dp[i][j] = subcost + acc[j] - acc[i];
        }
    }

    cout << dp[0][N] << endl;
}