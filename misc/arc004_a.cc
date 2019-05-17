// https://arc004.contest.atcoder.jp/tasks/arc004_1

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> pairs;
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        pairs.push_back(make_pair(x, y));
    }

    double res;
    for (int i = 0; i < N; ++i)
    {
        for (int k = 0; k < i; ++k)
        {
            double dist = hypot(pairs[i].first - pairs[k].first, pairs[i].second - pairs[k].second);
            res = max(res, dist);
        }
    }

    cout.precision(16);
    cout << res << endl;
}