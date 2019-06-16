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

int N, K;

int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> K;
    vector<double> prob(K + 1);

    for (int i = 1; i <= N; ++i) prob[min(i, K)] += 1.0 / N;

    for (int i = 1; i < K; ++i) prob[min(2*i, K)] += 0.5 * prob[i];

    cout.precision(12);
    cout << prob[K] << endl;

    return 0;
}
