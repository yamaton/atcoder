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

fn digitsum(x: u32) -> u32 {
    x.to_string().chars().map(|c| c.to_digit(10).unwrap()).sum()
}

fn main () {
    let n: u32 = read();
    let a: u32 = read();
    let b: u32 = read();
    let ans: u32 = (1..n+1).filter(|&x| {
        let dsum = digitsum(x);
        a <= dsum && dsum <= b
    }).sum();
    println!("{}", ans);
}