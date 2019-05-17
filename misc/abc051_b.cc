// https://atcoder.jp/contests/abc051/tasks/abc051_b

#include <iostream>
using namespace std;

int main()
{
    int K, S;
    cin >> K >> S;

    int res = 0;
    for (int p = 0; p <= K; ++p)
    {
        for (int q = 0; q <= K; ++q)
        {
            int r = S - p - q;
            if ((0 <= r) && (r <= K))
                ++res;
        }
    }
    cout << res << endl;
}
