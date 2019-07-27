#![allow(unused_variables)]
#![allow(unused_imports)]
#![allow(dead_code)]
use std::io;
use std::str::FromStr;
use std::iter::FromIterator;
use std::cmp::{max, min, Ordering};
use std::collections::*;
use std::mem::{replace, swap};

// [NOTE] trim() 入れないと RE になる
fn read_as_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

// -3.2
fn read_as_primitive<T: FromStr>() -> T {
    let s = read_as_line();
    s.trim().parse().ok().expect("failed to parse input")
}

// 1 -3 0 999
fn read_as_collection<U: FromStr, T: FromIterator<U>>() -> T {
    let s = read_as_line();
    s.trim().split_whitespace().map(|s| s.parse().ok().expect("failed to parse")).collect()
}

// #.#.###..
fn read_as_chars<T: FromIterator<char>>() -> T {
    let s = read_as_line();
    s.trim().chars().collect()
}

// 1 abc
fn read_as_pair<T: FromStr, U: FromStr>() -> (T, U) {
    let s = read_as_line();
    let mut it = s.trim().split_whitespace();
    (
        it.next().unwrap().parse().ok().expect("failed to parse"),
        it.next().unwrap().parse().ok().expect("failed to parse"),
    )
}

// 1.5 -2 abc
fn read_as_triple<T: FromStr, U: FromStr, V: FromStr>() -> (T, U, V) {
    let s = read_as_line();
    let mut it = s.trim().split_whitespace();
    (
        it.next().unwrap().parse().ok().expect("failed to parse"),
        it.next().unwrap().parse().ok().expect("failed to parse"),
        it.next().unwrap().parse().ok().expect("failed to parse"),
    )
}

// ==================================================================

fn main() {
    // // 3
    let n: i64 = read_as_primitive();

    // -3 abc
    let (n, k): (usize, usize) = read_as_pair();

    // 11 -3 2 3 0
    let xs: Vec<i64> = read_as_collection();

    // vec!['a', 'b', 'c', 'd']
    let cs: Vec<char> = read_as_chars();

    // 1.3 -3 abc
    let (p, q, r): (f64, i64, String) = read_as_triple();

    // ####
    // #..#
    // .#.#
    let xss: Vec<Vec<char>> = (0..3).map(|_| read_as_chars()).collect();

    let mut ans = 0;
    println!("{}", ans);

}