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
    let ss: String = read();
    let mut s = &ss[..];
    let words = ["dream", "dreamer", "erase", "eraser"];

    let mut found = false;
    while !s.is_empty() {
        found = false;
        for w in &words {
            if s.ends_with(w) {
                s = &s[0..s.len() - w.len()];
                found = true;
            }
        }
        if !found {
            break;
        }
    }

    let ans = if found {"YES"} else {"NO"};

    println!("{}", ans);
}