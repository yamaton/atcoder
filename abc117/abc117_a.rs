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

fn main() {
    let (t, x): (f64, f64) = read_as_pair();
    println!("{:.10}", t/x);
}