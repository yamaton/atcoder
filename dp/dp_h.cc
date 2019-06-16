// https://atcoder.jp/contests/dp/tasks/dp_h
#include <assert.h>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

const long long BIGINT = (long long)1e9 + 7;
int H, W;
string s;
long long dp[1005][1005];

int main()
{
    cin >> H >> W;
    for (int i = 1; i <= H; ++i) {
        cin >> s;
        for (int j = 1; j <= W; ++j) {
            int idx = j - 1;
            if (i == 1 && j == 1)
                dp[i][j] = 1LL;
            else if (s[idx] == '#')
                dp[i][j] = 0LL;
            else {
                assert(s[idx] == '.');
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % BIGINT;
            }
        }
    }
    cout << dp[H][W] << endl;

    return 0;
}