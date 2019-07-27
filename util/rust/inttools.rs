use std::mem;

fn length_in_base2(x: usize) -> usize {
    let mut x = x;
    let mut ans = 0;
    while x > 0 {
        ans += 1;
        x >>= 1;
    }
    ans
}


fn powmod(x: i64, y: usize, z: i64) -> i64 {
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


fn gcd(mut x: i64, mut y: i64) -> i64 {
    assert!(x >= 0 && y >= 0);
    if x < y {
        mem::swap(&mut x, &mut y);
    }

    if y == 0 {
        return x;
    }

    gcd(y, x % y)
}


fn lcm(x: i64, y: i64) -> i64 {
    assert!(x >= 0 && y >= 0);
    x / gcd(x, y) * y
}

fn integerdigits(n: i64) -> Vec<i64> {
    let s = n.to_string();
    assert!(s.chars().next().unwrap() != '-');
    s.chars().map(|c| c.to_digit(10).unwrap() as i64).collect()
}

fn fromdigits(xs: &[i64]) -> i64 {
    assert!(xs.iter().all(|&x| x >= 0));
    xs.iter().fold(0, |acc, &x| 10 * acc + x as i64)
}

fn fromdigits2(xs: &[i64]) -> String {
    assert!(xs.iter().all(|&x| x >= 0));
    let v: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    v.join("")
}

fn main() {
    let x = 3424;
    let y = 4173;
    assert_eq!(gcd(x, y), 107);
    assert_eq!(lcm(x, y), 133536);
    assert_eq!(integerdigits(x), vec![3, 4, 2, 4]);
    assert_eq!(fromdigits(&vec![3, 4, 2, 4]), 3424);
    assert_eq!(fromdigits2(&vec![3, 4, 2, 4]), "3424");
    assert_eq!(x, fromdigits(&integerdigits(x)));

    let x = 1000000009_i64;
    assert_eq!(length_in_base2(x as usize), 30);
    assert_eq!(length_in_base2(4), 3);
    let y = 131;
    let z = 1000000007;
    assert_eq!(powmod(x, y, z), 237058202_i64);
}
