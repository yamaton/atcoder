#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
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
    int M, K;
    cin >> M >> K;
    if (K >= pow(2, M) or (M == 1 and K == 1))
    {
        cout << -1 << endl;
    }
    else if (M == 1 and K == 0)
    {
        cout << "0 0 1 1" << endl;
    }
    else
    {

        cout << K;
        for (int i = 0; i < pow(2, M); ++i)
            if (i != K)
                cout << " " << i;
        cout << " " << K;
        for (int i = pow(2, M) - 1; i >= 0; --i)
            if (i != K)
                cout << " " << i;
        cout << endl;
    }

    return 0;
}
