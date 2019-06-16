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


bool is_month(int x) {
    return (1 <= x and x <= 12);
}

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int first = stoi(s.substr(0, 2));
    int second = stoi(s.substr(2));

    if (is_month(first) and is_month(second)) cout << "AMBIGUOUS" << endl;
    else if (is_month(first) ) cout << "MMYY" << endl;
    else if (is_month(second)) cout << "YYMM" << endl;
    else cout << "NA" << endl;

    return 0;
}
