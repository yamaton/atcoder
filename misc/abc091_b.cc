// https://atcoder.jp/contests/abc091/tasks/abc091_b
#include <iostream>
#include <map>
using namespace std;

int N, M;
map<string, int> counter;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        counter[s]++;
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        counter[s]--;
    }

    int res = 0;
    for (auto const &item: counter) {
        res = max(res, item.second);
    }
    cout << res << endl;
}