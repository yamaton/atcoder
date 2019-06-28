/* 
    AtCoder 129 E
        - 桁DPの練習
        - バイナリで分かれるのなら、１次元ヴェクタを２つ持つほうが良いと思う
 */
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define DEBUG(x) cout << (#x) << ": " << (x) << endl
#define DEBUG_VEC(v)            \
    cerr << #v << ": ";         \
    REP(__i, (v).size())        \
    cerr << ((v)[__i]) << ", "; \
    cerr << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll BIGINT = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    vl dp_marginal(n + 1);
    vl dp_free(n + 1);

    assert(s[0] == '1');
    dp_marginal[0] = 2;
    dp_free[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        if (s[i] == '1')
        {
            dp_marginal[i] = (2 * dp_marginal[i - 1]) % BIGINT;
            dp_free[i] = (3 * dp_free[i - 1] + dp_marginal[i - 1]) % BIGINT;
        }
        else
        {
            dp_marginal[i] = dp_marginal[i - 1];
            dp_free[i] = (3 * dp_free[i - 1]) % BIGINT;
        }
    }

    cout << (dp_marginal[n - 1] + dp_free[n - 1]) % BIGINT << endl;
    return 0;
}
