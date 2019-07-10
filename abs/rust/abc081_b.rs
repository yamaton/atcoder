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

fn get_count(mut x: u32) -> u32 {
    let mut cnt = 0;
    while x % 2 == 0 {
        x = x / 2;
        cnt += 1;
    }
    cnt
}

fn main() {
    let n: u32 = read();
    let a: Vec<u32> = (0..n).map(|_| read::<u32>()).collect();
    let ans = a.iter().map(|&x| get_count(x)).min().unwrap();
    println!("{}", ans);
}