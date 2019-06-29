#include <vector>
using namespace std;

template<typename T>
vector<pair<T, int>> grouper(vector<T> xs) {
    int n = xs.size();
    vector<bool> done(n);
    vector<pair<T, int> res;

    for(int i = 0; i < n; ++i)
    {
        if (done[i])
            continue;
        auto x = xs[i];
        done[i] = true;
        int j = i + 1;
        int cnt = 1;
        while (j < n and xs[j] == x)
        {
            cnt++;
            done[j] = true;
            j++;
        }
        res.emplace_back(x, cnt);
    }
    return res;
}