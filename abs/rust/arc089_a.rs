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
    let mut p: (i32, i32) = (0, 0);
    let mut t_prev: i32 = 0;

    let mut plausible = true;
    for _ in 0..n {
        let t: i32 = read();
        let x: i32 = read();
        let y: i32 = read();
        let diff = (t - t_prev) - ((x - p.0).abs() + (y - p.1).abs());
        if diff < 0 || diff % 2 > 0
         {
            plausible = false;
            break;
        }
        t_prev = t;
        p = (x, y);
    }
    let ans = if plausible {"Yes"} else {"No"};
    println!("{}", ans);
}