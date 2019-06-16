#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <cctype>

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
    string s;
    cin >> N >> K;
    cin >> s;
    s[K-1] = tolower(s[K-1]);
    cout << s << endl;
}
