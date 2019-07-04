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
#include <utility>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define DEBUG(x) cerr << (#x) << ": " << (x) << endl
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

int gcd(int x, int y) {
    if (y > x) swap(x, y);
    if (y == 0) return x;
    return gcd(y, x % y);
}


int main()
{
    ios::sync_with_stdio(false);
    int A, B, K;
    cin >> A >> B >> K;

    int g = gcd(A, B);
    vi xs;
    xs.push_back(1);
    for (int i = 2; i <= (int) sqrt(g); ++i) {
        if (g % i == 0) {
            xs.push_back(i);
            if (i * i != g) xs.push_back(g / i);
        }
    }
    xs.push_back(g);
    sort(xs.begin(), xs.end());
    cout << xs[xs.size() - K] << endl;

    return 0;
}
