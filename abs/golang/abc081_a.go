package main

import (
	"fmt"
	"strings"
)

func main() {
	var (
		s   string
		cnt int
	)

	fmt.Scan(&s)
	cnt = strings.Count(s, "1")
	fmt.Println(cnt)
}
