package main

import "fmt"

func coin(rest, a, b, c int) int {
	var ans int
	if rest == 0 {
		ans = 1
	} else if rest < 0 {
		ans = 0
	} else if a > 0 {
		ans = coin(rest-500, a-1, b, c) + coin(rest, 0, b, c)
	} else if b > 0 {
		ans = coin(rest-100, a, b-1, c) + coin(rest, a, 0, c)
	} else if c > 0 {
		ans = coin(rest-50, a, b, c-1) + coin(rest, a, b, 0)
	} else {
		ans = 0
	}

	return ans
}

func main() {
	var (
		a, b, c, x int
	)

	fmt.Scan(&a, &b, &c, &x)
	fmt.Println(coin(x, a, b, c))
}
