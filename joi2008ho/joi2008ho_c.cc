#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

int binary_search(vector<int> & arr, int key) {

    auto is_ok = [&](int index) {
        return (arr[index] <= key);
    };

    int ok = -1;
    int ng = arr.size();

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (is_ok(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int solve(vector<int> & p, int n, int m) {
    p.push_back(0);

    vector<int> q;
    for (int i = 0; i <= n; ++i) {
        for (int k = i; k <= n; ++k ) {
            int twosum = p[i] + p[k];
            if (twosum <= m) q.push_back(twosum);
        }
    }
    sort(q.begin(), q.end());

    int res = -1000;
    for (auto x: q) {
        int idx = binary_search(q, m - x);
        int total = q[idx] + x;
        if (total > res) res = total;
    }
    return res;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    cout << solve(p, n, m) << endl;
}