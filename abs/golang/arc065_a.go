package main

import "fmt"

func main() {
	var (
		s string
	)
	fmt.Scan(&s)
	stock := []string{"dream", "dreamer", "erase", "eraser"}

	for len(s) > 0 {
		found := false
		for k := 0; k < len(stock); k++ {
			tmp := stock[k]
			pos := len(s) - len(tmp)
			if pos >= 0 && s[pos:] == tmp {
				s = s[:pos]
				found = true
			}
		}
		if !found {
			break
		}
	}

	if len(s) == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}

}
