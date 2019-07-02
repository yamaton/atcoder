// Meguru-shiki binary search
// https://qiita.com/drken/items/97e37dd6143e33a64c8c

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


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
template <typename T>
int binary_search(std::vector<T>& seq, T key)
{
    auto is_ok = [&](int index) { return seq[index] >= key; };
    int ng = -1;
    int ok = seq.size();

    while (std::abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (is_ok(mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main()
{
    //                   0   1   2   3   4   5    6    7    8    9
    std::vector<int> xs{ 1, 14, 32, 51, 51, 51, 243, 419, 750, 910 };
    assert(binary_search(xs, 51) == 3);
    assert(binary_search(xs, 1) == 0);
    assert(binary_search(xs, 910) == 9);
    assert(binary_search(xs, 52) == 6);
    assert(binary_search(xs, 0) == 0);
    assert(binary_search(xs, 911) == 10);
}
