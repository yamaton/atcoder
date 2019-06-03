#include <iostream>
#include <vector>
using namespace std;

int N;
int h[100005];
long long dp[100005];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> h[i];
    }

    dp[1] = 0LL;
    for (int x = 2; x <= N; ++x) {
        dp[x] = dp[x - 1] + abs(h[x] - h[x - 1]);
        if (x >= 3)
            dp[x] = min(dp[x], dp[x - 2] + abs(h[x] - h[x - 2]));
    }

    cout << dp[N] << endl;
}