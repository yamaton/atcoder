#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int H, W;

int main()
{
    ios::sync_with_stdio(false);

    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    vector<vi> res(H, vi(W));
    rep(i, H)
    {
        vector<bool> done(W);
        rep(j, W)
        {
            if (done[j])
                continue;

            if (grid[i][j] == '#')
            {
                res[i][j] = 0;
                continue;
            }

            int k = 0;
            while (j + k < W)
            {
                if (grid[i][j + k] == '#')
                    break;
                k++;
            }

            rep(l, k)
            {
                res[i][j + l] += k;
                done[j + l] = true;
            }
        }
    }

    rep(i, W)
    {
        vector<bool> done(H);
        rep(j, H)
        {
            if (done[j])
                continue;

            if (grid[j][i] == '#')
            {
                res[j][i] = 0;
                continue;
            }

            int k = 0;
            while (j + k < H)
            {
                if (grid[j + k][i] == '#')
                    break;
                k++;
            }

            rep(l, k)
            {
                res[j + l][i] += k;
                done[j + l] = true;
            }
        }
    }

    int ans = 0;
    rep(i, H) rep(j, W) ans = max(res[i][j] - 1, ans);

    cout << ans << endl;
}
