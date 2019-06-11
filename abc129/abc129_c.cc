#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const long long BIGINT = 1e9 + 7;
int N, M;

int main()
{
    ios::sync_with_stdio(false);

    cin >> N >> M;

    vector<bool> not_ok(N + 1);
    rep(i, M)
    {
        int tmp;
        cin >> tmp;
        not_ok[tmp] = true;
    }

    vector<ll> dp(N + 3);
    dp[0] = 1LL;
    for (int i = 1; i <= N; ++i)
    {
        if (not_ok[i])
            dp[i] = 0LL;
        else
        {
            if (i == 1)
                dp[i] = dp[i - 1];
            else
                dp[i] = (dp[i - 1] + dp[i - 2]) % BIGINT;
        }
    }
    cout << dp[N] << endl;

    return 0;
}
