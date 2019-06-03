// https://atcoder.jp/contests/dp/tasks/dp_g
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> adjlist(100004);
vector<int> memo(100004);

int depth(int start)
{
    if (memo[start] > 0)
        return memo[start];

    int res = 0;
    for (auto& next : adjlist[start]) {
        res = max(res, 1 + depth(next));
    }
    return memo[start] = res;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tmpx, tmpy;
        cin >> tmpx >> tmpy;
        adjlist[tmpx].push_back(tmpy);
    }

    int res = 0;
    for (int i = 1; i <= N; ++i)
        res = max(res, depth(i));

    cout << res << endl;

    return 0;
}