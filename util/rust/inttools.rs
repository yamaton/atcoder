use std::mem;

fn gcd(mut x: u64, mut y: u64) -> u64 {
    if x < y {
        mem::swap(&mut x, &mut y);
    }

    if y == 0 {
        return x;
    }

    gcd(y, x % y)
}


fn lcm(x: u64, y: u64) -> u64 {
    x / gcd(x, y) * y
}


fn integerdigits(n: u64) -> Vec<u32> {
    let s = n.to_string();
    s.chars().map(|c| c.to_digit(10).unwrap()).collect()
}

fn fromdigits(xs: &[u32]) -> u64 {
    xs.iter().fold(0, |acc, &x| 10 * acc + x as u64)
}

fn main() {
    let x = 3424;
    let y = 4173;
    assert_eq!(gcd(x, y), 107);
    assert_eq!(lcm(x, y), 133536);
    assert_eq!(integerdigits(x), vec![3, 4, 2, 4]);
    assert_eq!(fromdigits(&vec![3, 4, 2, 4]), 3424);
    assert_eq!(x, fromdigits(&integerdigits(x)));
}
