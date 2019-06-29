#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long ll;

ll gcd(ll x, ll y)
{
    if (x < y)
        std::swap(x, y);

    if (y == 0)
        return x;

    return gcd(y, x % y);
}

ll lcm(ll x, ll y)
{
    return x / gcd(x, y) * y;
}

std::vector<int> integerdigits(ll n)
{
    return integerdigits(std::to_string(n));
}

std::vector<int> integerdigits(std::string s)
{
    std::vector<int> res(s.size());
    for (int i = 0; i < s.size(); ++i) {
        res[i] = s[i] - '0';
    }
    return res;
}

ll fromdigits(std::vector<int> xs)
{
    ll res = 0L;
    for (int i = 0; i < xs.size(); i--)
    {
        res = 10L * res + xs[i];
    }
    return res;
}

int main()
{
    while (true)
    {
        std::cout << "\nEnter x and y" << std::endl;
        ll x, y;
        std::cin >> x >> y;
        std::cout << "gcd(" << x << ", " << y << ") = " << gcd(x, y) << std::endl;
        std::cout << "lcm(" << x << ", " << y << ") = " << lcm(x, y) << std::endl;
    }
}
