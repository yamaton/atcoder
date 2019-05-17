// https://atcoder.jp/contests/abc104/tasks/abc104_c
#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000007;

int main()
{
    int D, G;
    cin >> D >> G;
    vector<int> p(D), c(D);
    for (int i = 0; i < D; ++i)
    {
        cin >> p[i];
        cin >> c[i];
    }

    cout << "[debug] D " << D << endl;
    cout << "[debug] G " << G << endl;
    cout << "[debug] p ";
    for (auto pi : p)
        cout << pi << " ";
    cout << endl;

    cout << "[debug] c ";
    for (auto ci : c)
        cout << ci << " ";
    cout << endl;

    int res = INF;
    for (int n = 0; n <= (1 << D); ++n)
    {
        int count = 0;
        int rest = G;
        int record = 0;

        for (int k = 0; k < D; ++k)
        {
            if (((n >> k) & 1) == 1)
            {
                int item_sum = (k + 1) * 100 * p[k] + c[k];
                count += p[k];
                rest -= item_sum;
                record |= (1 << k);
            }
        }
        cout << "---------------" << endl;
        cout << "[debug] n = " << n << endl;
        cout << "[debug] count " << count << endl;
        cout << "[debug] rest " << rest << endl;
        cout << "[debug] record " << record << endl;

        for (int l = D - 1; l >= 0; --l)
        {
            if (rest <= 0)
                break;

            int item_value;
            if ((record >> l) & 1 == 0)
            {
                item_value = 100 * (l + 1);
                int decr = min((rest + item_value - 1) / item_value, p[l]);
                rest -= 100 * decr;
                count += count + decr;
                cout << "  [debug] item_value " << item_value << endl;
                cout << "  [debug] count " << count << endl;
                cout << "  [debug] rest " << rest << endl;
                cout << "  [debug] record " << record << endl;
            }
        }
        if (count > 0 && rest <= 0)
            res = min(res, count);
    }
    cout << res << endl;
}
