package main

import "fmt"

func main() {
	var (
		a, b int
		s    string
	)

	fmt.Scan(&a, &b)
	if (a*b)%2 == 0 {
		s = "Even"
	} else {
		s = "Odd"
	}

	fmt.Println(s)
}
