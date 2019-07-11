// めぐる式にぶたん
//   key <= seq[i] となる状態を ok とする 
//      (== bisect.bisect_left, lower_bound(seq.begin(), seq.end(), key))
//   key <  seq[i] となる状態を ok とする 
//      (== bisect.bisect_right, upper_bound(seq.begin(), seq.end(), key))
// 
// 返り値 idx に対して
//        seq[idx] 以降が ok
//        seq[idx] 未満が ng
//
// すべて ok のばあいは idx=0
// すべて ng のばあいは idx=seq.size() （範囲外）
//

fn binary_search<T: Ord>(seq: &[T], key: T) -> usize
{
    // fn is_ok(index: i32) -> bool {
    //     let ans = (seq[index] >= key);
    //     ans
    // }
    let is_ok = |index: i32| seq[index as usize] >= key;
    let mut ng: i32 = -1;
    let mut ok: i32 = seq.len() as i32;

    while (ok - ng).abs() > 1 {
        let mid = (ok + ng) / 2;
        if is_ok(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    ok as usize
}

fn main()
{
    //            0   1   2   3   4   5    6    7    8    9
    let xs = vec![1, 14, 32, 51, 51, 51, 243, 419, 750, 910];
    assert_eq!(binary_search(&xs, 51), 3);
    assert_eq!(binary_search(&xs, 1), 0);
    assert_eq!(binary_search(&xs, 910), 9);
    assert_eq!(binary_search(&xs, 52), 6);
    assert_eq!(binary_search(&xs, 0), 0);
    assert_eq!(binary_search(&xs, 911), 10);
}