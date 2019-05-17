// https://abc085.contest.atcoder.jp/tasks/abc085_c
#include <iostream>
#include <tuple>
using namespace std;

tuple<int, int, int> solve(int N, int Y)
{
    for (int tens = 0; tens <= N; ++tens)
    {
        for (int fives = 0; fives <= N; ++fives)
        {
            int ones = (Y - 10000 * tens - 5000 * fives) / 1000;
            if ((0 <= ones) && (ones + fives + tens == N))
                return make_tuple(tens, fives, ones);
        }
    }
    return make_tuple(-1, -1, -1);
}

int main()
{
    int N, Y;
    cin >> N >> Y;
    auto res = solve(N, Y);
    cout << get<0>(res) << " " << get<1>(res) << " " << get<2>(res) << endl;
    return 0;
}
