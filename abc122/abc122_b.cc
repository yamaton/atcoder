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
#include <deque>
#include <stack>
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

string ACGT = "ACGT";

bool isAtgc(char c) {
    bool ok = false;
    REP(i, 4) if (ACGT[i] == c) ok = true;
    return ok;
}

int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    
    int res = 0;
    int curr = 0;
    REP(i, s.size()) {
        if (isAtgc(s[i])) {
            curr += 1;
            res = max(res, curr);
        } else {
            curr = 0;
        }
    }
    cout << res << endl;
    return 0;
}
