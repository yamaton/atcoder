package main

import "fmt"

func count(x int) int {
	var cnt int

	for x%2 == 0 {
		x /= 2
		cnt++
	}

	return cnt
}

func main() {

	var (
		n int
	)

	fmt.Scan(&n)
	xs := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&xs[i])
	}

	res := 100000000009
	for i := 0; i < n; i++ {
		cnt := count(xs[i])
		if cnt < res {
			res = cnt
		}
	}

	fmt.Println(res)
}
