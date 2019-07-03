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


const int INF = 1e9;
int N, A, B, C;
vi l;


// a is accumulated sum of sticks for A
// analogously b for B, c for C
int dfs(int depth, int a, int b, int c) {
    if (depth == N)
        if (a > 0 and b > 0 and c > 0)
            return abs(a - A) + abs(b - B) + abs(c - C) - 30;
        else
            return INF;
    
    int res0 = dfs(depth + 1, a, b, c);
    int res1 = dfs(depth + 1, a + l[depth], b, c) + 10;
    int res2 = dfs(depth + 1, a, b + l[depth], c) + 10;
    int res3 = dfs(depth + 1, a, b, c + l[depth]) + 10;
    return min({res0, res1, res2, res3});
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> A >> B >> C;
    l.resize(N);
    REP(i, N) cin >> l[i];

    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}
