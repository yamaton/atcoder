#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <tuple>
#include <stack>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N;
vector<ii> adj_list[100001];
vi color;

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    color.resize(N + 1, -1);

    int u, v, w;
    rep(i, N - 1)
    {
        cin >> u >> v >> w;
        adj_list[u].emplace_back(v, w);
        adj_list[v].emplace_back(u, w);
    }

    color[1] = 0;
    stack<int> stk;
    stk.push({1});

    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();
        // cerr << "curr: " << curr << endl;
        for (auto &pair : adj_list[curr])
        {
            int node = pair.first;
            int dist = pair.second;
            if (color[node] == -1)
            {
                int c = (dist + color[curr]) % 2;
                stk.push(node);
                color[node] = c;
            }
        }
    }

    for (int i = 1; i <= N; ++i)
        cout << color[i] << endl;
}
