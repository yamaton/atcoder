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
    let n: i32 = read();
    let y: i32 = read();
    let mut done = false;

    let mut ans = (-1, -1, -1);
    for i in 0..n+1 {
        for j in 0..n-i+1 {
            let k = n - i - j;
            if 10000 * i + 5000 * j + 1000 * k == y {
                ans = (i, j, k);
                done = true;
                break;
            }
        }
        if done {
            break;
        }
    }

    println!("{} {} {}", ans.0, ans.1, ans.2);
}