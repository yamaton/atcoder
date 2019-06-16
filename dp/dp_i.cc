// https://atcoder.jp/contests/dp/tasks/dp_i
#include <iostream>
using namespace std;

int N;
double p;
double dp[3005];

int main()
{
    cin >> N;
    dp[0] = 1.0;
    for (int i = 1; i <= N; ++i) {
        cin >> p;
        for (int j = i; j >= 0; --j) {
            double tmp = dp[i];
            dp[j] = p * dp[j] + (1 - p) * dp[j - 1];
        }
    }
    double res = 0.0;
    for (int i = 0; i < (N + 1) / 2; ++i){
        res += dp[i];
    }
    cout.precision(10);
    cout << res << endl;

    return 0;
}