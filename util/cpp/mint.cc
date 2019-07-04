/* 
Shameless copy of snuke's implementation at AtCoder Live

 */

#include <vector>
using namespace std;

type long long ll;

const ll BIGINT = 1e9 + 7;


struct mint {
  ll x;
  mint(ll x = 0) : x(x % BIGINT) {}

  mint& operator+=(const mint a) {
    if ((x += a.x) >= BIGINT) x -= BIGINT;
    return *this;
  }

  mint& operator-=(const mint a) {
        if ((x += (BIGINT - a.x) >= BIGINT) x -= BIGINT;
        return *this;
  }

  mint& operator*=(const mint a) {
    (x *= a.x) %= BIGINT;
    return this;
  }

  mint& operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }

  mint& operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }

  mint& operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
}