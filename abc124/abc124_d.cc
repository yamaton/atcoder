/* 
しゃくとり法

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

int main()
{
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    vi high;
    vi low;
    vector<bool> done(N);
    if (s[0] == '0')
        high.push_back(0);
    REP(i, N)
    {
        if (done[i])
            continue;
        char c = s[i];
        done[i] = true;
        int j = i + 1;
        int cnt = 1;
        while (j < N and s[j] == c)
        {
            cnt++;
            done[j] = true;
            j++;
        }
        if (c == '0')
            low.push_back(cnt);
        else
            high.push_back(cnt);
    }
    if (s[N - 1] == '0')
        high.push_back(0);

    // cerr << "high:";
    // for (auto x : high)
    //     cerr << " " << x;
    // cerr << endl;

    // cerr << "low:";
    // for (auto x : low)
    //     cerr << " " << x;
    // cerr << endl;

    if (low.size() <= K)
    {
        cout << s.size() << endl;
        return 0;
    }

    int total = 0;
    REP(i, K + 1) total += high[i];
    REP(i, K) total += low[i];

    int p = K;
    int res = total;
    while (p < low.size())
    {
        total += high[p + 1] - high[p - K] + low[p] - low[p - K];
        res = max(res, total);
        p++;
    }

    cout << res << endl;
    return 0;
}
