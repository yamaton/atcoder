#include <algorithm>
#include <iostream>

using namespace std;
string s, t;
int dp[3005][3005];

int main()
{
    cin >> s;
    cin >> t;
    int s_len = s.size();
    int t_len = t.size();
    for (int i = 1; i <= s_len; ++i) {
        for (int j = 1; j <= t_len; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cerr << dp[s_len][t_len] << endl;

    string ans = "";
    int i = s.size();
    int j = t.size();
    while (i > 0 || j > 0) {
        if (i && dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (j && dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            ans += s[i - 1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cerr << ans.size() << endl;

    cout << ans << endl;

    return 0;
}