// https://atc001.contest.atcoder.jp/tasks/unionfind_a

#include<iostream>
#include<vector>
using namespace std;

int N, Q;
int P, A, B;
vector<int> uf;


int get_root(int x) {
    while (uf[x] >= 0) {
        x = uf[x];
    }
    return x;
}

bool is_connected(int i, int j) {
    bool res = (get_root(i) == get_root(j));
    return res;
}

int size(int i) {
    return (- uf[get_root(i)]);
}

void connect(int x, int y) {
    int root_x = get_root(x);
    int root_y = get_root(y);

    if (size(root_x) > size(root_y)) {
        return connect(y, x);
    }
    uf[root_y] = - (size(root_x) + size(root_y));
    uf[root_x] = root_y;
}


int main() {
    cin >> N >> Q;
    for (int i = 0; i < N + 1; ++i) {
        uf.push_back(-1);
    }

    for (int i = 0; i < Q; ++i) {
        cin >> P >> A >> B;
        if (P == 0) {
            if (! is_connected(A, B)) {
                connect(A, B);
            }
        } else {
            string ans = (is_connected(A, B) ? "Yes" : "No");
            cout << ans << endl;
        }
    }
}