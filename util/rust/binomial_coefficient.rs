const BIGINT: i64 = 1e9 as i64 + 7;


fn length_in_base2(x: i64) -> i64 {
    let mut x = x;
    let mut ans = 0;
    while x > 0 {
        ans += 1;
        x >>= 1;
    }
    ans
}

fn powmod(x: i64, y: i64, z: i64) -> i64 {
    let mut ans = 1_i64;
    let mut px = x;
    let y_size = length_in_base2(y);
    for i in 0..y_size {
        if (y >> i) & 1 == 1 {
            ans = (ans * px) % z;
        }
        px = (px * px) % z;
    }
    ans
}

fn modinv(a: i64, p: i64) -> i64 {
    powmod(a, p - 2, p)
}

fn binomial_coeff(n: i64, r: i64, z:i64) -> i64 {
    if n < r {
        return 0;
    }
    if 2 * r > n {
        return binomial_coeff(n, n - r, z);
    }

    let mut numer = 1;
    let mut denom = 1;
    let mut n = n;
    let mut r = r;
    for _ in 0..r {
        numer = (numer * n) % z;
        denom = (denom * r) % z;
        n -= 1;
        r -= 1;
    }
    let ans = (numer * modinv(denom, z)) % z;
    ans
}

fn main() {
    assert_eq!(binomial_coeff(5, 2, BIGINT), 10);
    assert_eq!(binomial_coeff(64, 32, BIGINT), 114221638);
    assert_eq!(binomial_coeff(100, 20, BIGINT), 926116413);
}
