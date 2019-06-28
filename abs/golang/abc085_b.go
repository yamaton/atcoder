package main

import "fmt"

func main() {
	var (
		n   int
		tmp int
	)
	fmt.Scan(&n)
	set := map[int]bool{}
	for i := 0; i < n; i++ {
		fmt.Scan(&tmp)
		set[tmp] = true
	}

	fmt.Println(len(set))

}
