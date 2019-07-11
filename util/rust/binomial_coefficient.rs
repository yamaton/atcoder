const BIGINT: u64 = 1_000_000_007;

fn pow(mut x: u64, n: u64) -> u64 {
    let mut ans: u64 = 1;
    let mut nn = n;
    let mut k = 0;
    while nn > 0 {
        nn = nn >> 1;
        k += 1
    }
    for i in 0..k {
        if (n >> i) & 1 > 0 {
            ans = (ans * x) % BIGINT;
        }
        x = (x * x) % BIGINT;
    }
    ans
}

fn modinv(a: u64, p: u64) -> u64 {
    pow(a, p - 2)
}

fn binomial_coeff(mut n: u64, r: u64) -> u64 {
    if n < r {
        return 0;
    }
    if 2 * r > n {
        return binomial_coeff(n, n - r);
    }

    let mut numer = 1;
    let mut denom = 1;
    let mut k = r;
    for _ in 0..r {
        numer = (numer * n) % BIGINT;
        denom = (denom * k) % BIGINT;
        n -= 1;
        k -= 1;
    }
    let ans = (numer * modinv(denom, BIGINT)) % BIGINT;
    ans
}

fn main() {
    assert_eq!(binomial_coeff(5, 2), 10);
    assert_eq!(binomial_coeff(64, 32), 114221638);
    assert_eq!(binomial_coeff(100, 20), 926116413);
}
