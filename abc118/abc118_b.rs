// https://qiita.com/tubo28/items/e6076e9040da57368845

use std::io::*;
use std::str::FromStr;
use std::collections::HashMap;

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

fn main() {
    let n: u32 = read();
    let _: u32 = read();

    let mut d = HashMap::new();
    for _ in 0..n {
        let k: u32 = read();
        let xs: Vec<_> = (0..k).map(|_| read::<u32>()).collect();
        for x in xs {
            (*d.entry(x).or_insert(0)) += 1;
        }
    }
    let ans = d.iter().filter(|&(_, &v)| v == n).count();
    println!("{}", ans);
}