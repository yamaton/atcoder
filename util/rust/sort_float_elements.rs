// Sorting ParitialOrd primitives like f64
// let mut v: Vec<f64> = vec![0.1, 1.0, 2.0, 0.5];
// v.sort_by_key(|&x| Total(x));
// 
// src: https://qiita.com/hatoo@github/items/fa14ad36a1b568d14f3e
//      https://github.com/rust-lang/rust/pull/53938
//
#[derive(PartialEq, PartialOrd)]
pub struct Total<T>(pub T);

impl<T: PartialEq> Eq for Total<T> {}

impl<T: PartialOrd> Ord for Total<T> {
    fn cmp(&self, other: &Total<T>) -> std::cmp::Ordering {
        self.0.partial_cmp(&other.0).unwrap()
    }
}