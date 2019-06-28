package main

import (
	"fmt"
	"sort"
)

func abs(a int) int {
	if a < 0 {
		a = -a
	}
	return a
}

func main() {
	var (
		n    int
		a, b int
	)

	fmt.Scan(&n)
	xs := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&xs[i])
	}
	sort.Sort(sort.Reverse(sort.IntSlice(xs)))
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			a += xs[i]
		} else {
			b += xs[i]
		}
	}
	fmt.Println(abs(a - b))
}
