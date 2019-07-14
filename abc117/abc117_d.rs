#![allow(unused_variables)]
#![allow(unused_imports)]
#![allow(dead_code)]
use std::io;
use std::str::FromStr;
use std::iter::FromIterator;
use std::cmp::{max, min, Ordering};
use std::collections::*;
use std::mem::{replace, swap};


// abcde
fn read_string() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

// -3.2
fn read_as_primitive<T: FromStr>() -> T {
    let s = read_string();
    s.trim().parse().ok().expect("failed to parse input")
}

// 1 -3 0 999
fn read_as_collection<U: FromStr, T: FromIterator<U>>() -> T {
    let s = read_string();
    s.trim().split_whitespace().map(|s| s.parse().ok().expect("failed to parse")).collect()
}

// #.#.###..
fn read_as_chars<T: FromIterator<char>>() -> T {
    let s = read_string();
    s.trim().chars().collect()
}

// 1 abc
fn read_as_pair<T: FromStr, U: FromStr>() -> (T, U) {
    let s = read_string();
    let elems: Vec<_> = s.trim().split_whitespace().collect();    
    (
        elems[0].parse().ok().expect("failed to parse"), 
        elems[1].parse().ok().expect("failed to parse"),
    )
}

// 1.5 -2 abc
fn read_as_triple<T: FromStr, U: FromStr, V: FromStr>() -> (T, U, V) {
    let s = read_string();
    let elems: Vec<_> = s.trim().split_whitespace().collect();
    (
        elems[0].parse().ok().expect("failed to parse"), 
        elems[1].parse().ok().expect("failed to parse"),
        elems[2].parse().ok().expect("failed to parse"),
    )
}

fn get_digit_estimate(xs: &[u64], d: i32) -> u64 {
    let digits: Vec<u64> = xs.iter().map(|&x| x >> d).collect();
    let zero_count = digits.iter().filter(|&x| *x == 0).count();
    let one_count = digits.len() - zero_count;
    let res = if zero_count > one_count {1} else {0};
    res
}


fn main() {
    let (n, k): (usize, u64) = read_as_pair();
    let xs: Vec<u64> = read_as_collection();
    let mut mut_k = k;

    let mut n_digits: i32 = 0;
    while mut_k > 0 {
        n_digits += 1;
        mut_k = mut_k >> 1;
    }

    let mut is_marginal = true;
    let mut x: u64 = 1;
    for i in (0..n_digits-1).rev() {
        let d_k = (k >> i) & 1;
        let d = get_digit_estimate(&xs, i);
        if is_marginal && d_k == 1 && d == 0 {
            is_marginal = false;
        }
        let d_next = if is_marginal {d_k} else {d};
        x = x * 2 + d_next;
    }
    // this is too ad hoc!
    if k == 0 {
        x = 0;
    }

    let ans: u64 = xs.iter().map(|a| a^x).sum();
    println!("{}", ans);
}
