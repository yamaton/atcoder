// https://atc001.contest.atcoder.jp/tasks/dfs_a
#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, int> coord;

int H, W;
stack<coord> stk;
bool seen[501][501];
char grid[501][501];
coord start, goal;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    cin >> H >> W;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            char tmp;
            cin >> tmp;
            grid[i][j] = tmp;
            seen[i][j] = false;
            if (tmp == 's')
                start = make_pair(i, j);
            else if (tmp == 'g')
                goal = make_pair(i, j);
        }
    }

    bool flg = false;
    stk.push(start);
    seen[start.first][start.second] = true;
    while (!stk.empty())
    {
        auto state = stk.top();
        stk.pop();
        if (state == goal)
        {
            flg = true;
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            int r = state.first + dx[i];
            int c = state.second + dy[i];
            if (0 <= r && r < H && 0 <= c && c < W && grid[r][c] != '#' && !seen[r][c])
            {
                seen[r][c] = true;
                stk.emplace(make_pair(r, c));
            }
        }
    }
    string ans = flg ? "Yes" : "No";
    cout << ans << endl;
}
