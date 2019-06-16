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

class UnionFind
{

    std::vector<int> parent;

public:
    UnionFind(int n)
    {
        parent.resize(n, -1);
    }

    int root(int x)
    {
        while (parent[x] >= 0)
        {
            x = parent[x];
        }
        return x;
    }

    int size(int x)
    {
        return -parent[root(x)];
    }

    bool connect(int x, int y)
    {
        if (size(x) < size(y))
            std::swap(x, y);

        int root_x = root(x);
        int root_y = root(y);

        if (root_x == root_y)
            return false;

        parent[root_x] += parent[root_y];
        parent[root_y] = root_x;

        return true;
    }

    bool is_connected(int x, int y)
    {
        return (root(x) == root(y));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int N, M;

    cin >> N >> M;
    UnionFind uf(N + 1);

    cerr << endl;

    REP(i, M)
    {
        int x, y, z;
        cin >> x >> y >> z;
        uf.connect(x, y);
    }

    set<int> res;
    for (int i = 1; i <= N; ++i)
    {
        int r = uf.root(i);
        if (res.find(r) == res.end())
        {
            res.insert(r);
        }
    }

    cout << res.size() << endl;
    return 0;
}
