package main

import "fmt"

func digitsum(x int) int {
	var sum int
	for x > 0 {
		sum += x % 10
		x /= 10
	}
	return sum
}

func main() {
	var (
		n, a, b, ans int
	)

	fmt.Scan(&n, &a, &b)
	for i := 1; i <= n; i++ {
		if tmp := digitsum(i); a <= tmp && tmp <= b {
			ans += i
		}
	}
	fmt.Println(ans)
}
