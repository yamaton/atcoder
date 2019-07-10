// https://qiita.com/tubo28/items/e6076e9040da57368845

use std::io::*;
use std::str::FromStr;

fn read<T: FromStr>() -> T {
    let stdin = stdin();
    let stdin = stdin.lock();
    let token: String = stdin
        .bytes()
        .map(|c| c.expect("failed to read char") as char)
        .skip_while(|c| c.is_whitespace())
        .take_while(|c| !c.is_whitespace())
        .collect();
    token.parse().ok().expect("failed to parse token")
}

fn main () {
    let n: u32 = read();
    let mut xs: Vec<u32> = (0..n).map(|_| read()).collect();
    let total: u32 = xs.iter().sum();
    xs.sort_by(|a, b| a.cmp(b).reverse());
    let alice: u32 = xs.iter().step_by(2).sum();

    println!("{}", 2 * alice - total);
}