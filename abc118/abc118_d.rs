#![allow(unused_mut)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(unused_imports)]
#![allow(dead_code)]
use std::io;
use std::str::FromStr;
use std::iter::FromIterator;
use std::cmp::{max, min, Ordering};
use std::collections::*;
use std::mem::{replace, swap};

fn read_string() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_as_primitive<T: FromStr>() -> T {
    let s = read_string();
    s.trim().parse().ok().expect("failed to parse input")
}

fn read_as_collection<U: FromStr, T: FromIterator<U>>() -> T {
    let s = read_string();
    s.trim().split_whitespace().map(|s| s.parse().ok().expect("failed to parse")).collect()
}

fn read_as_pair<T: FromStr, U: FromStr>() -> (T, U) {
    let s = read_string();
    let elems: Vec<_> = s.trim().split_whitespace().collect();    
    (
        elems[0].parse().ok().expect("failed to parse"), 
        elems[1].parse().ok().expect("failed to parse"),
    )
}

fn fromdigits(xs: &[i32]) -> String {
    let v: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    v.join("")
}

fn main () {
    let (n, m): (i32, i32) = read_as_pair();
    let mut xs: Vec<i32> = read_as_collection();
    xs.sort_by(|a, b| b.cmp(a));

    let sticks = [2, 5, 5, 4, 5, 6, 3, 7, 6];
    let mut hm = BTreeMap::new();
    for (num, stk) in (1..10).zip(sticks.iter()) {
        hm.insert(num, stk);
    }

    let mut dp: Vec<i32> = vec![-100; 10_005];
    dp[0] = 0;
    for i in 1i32..n+1 {
        for k in &xs {
            let hm_k = *hm[k];
            if i - hm_k >= 0 {
                dp[i as usize] = max(dp[i as usize], dp[(i - hm_k) as usize] + 1);
            }
        }
    }

    let mut ans : Vec<i32> = Vec::new();
    let mut digit   _len = dp[n as usize];
    let mut matches = n;
    while digit_len > 0 {
        for k in &xs {
            let hm_k = *hm[k];
            if matches - hm_k >= 0 && dp[(matches - hm_k) as usize] == dp[matches as usize] - 1 {
                digit_len -= 1;
                matches -= hm_k;
                ans.push(*k);
                break;
            }
        }
    }
    
    println!("{}", fromdigits(&ans[..]));
}