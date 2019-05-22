// https://atcoder.jp/contests/abc085/tasks/abc085_b
#include <iostream>
#include <set>
using namespace std;

int N;
set<int> bag;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        bag.insert(x);
    }
    cout << bag.size() << endl;
}