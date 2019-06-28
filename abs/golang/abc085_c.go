package main

import "fmt"

func main() {
	var (
		n, y int
		res  [3]int
	)
	fmt.Scan(&n, &y)

	done := false
	for i := 0; i <= n; i++ {
		if !done {
			for j := 0; i+j <= n; j++ {
				k := n - i - j
				money := 10000*i + 5000*j + 1000*k
				if money == y {
					res = [3]int{i, j, k}
					done = true
					break
				}
			}
		}
	}
	if !done {
		res = [3]int{-1, -1, -1}
	}

	for i := 0; i < 3; i++ {
		fmt.Print(res[i])
		fmt.Print(" ")
	}
}
