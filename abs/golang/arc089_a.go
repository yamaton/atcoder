package main

import "fmt"

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func cannotArrive(t, x, y, t1, x1, y1 int) bool {
	deltaT := t1 - t
	deltaX := abs(x1 - x)
	deltaY := abs(y1 - y)
	dist := deltaX + deltaY
	return dist > deltaT || (deltaT-dist)%2 > 0
}

func main() {
	var (
		n, t, x, y int
		t1, x1, y1 int
	)
	fmt.Scan(&n)
	success := true

	for i := 0; i < n; i++ {
		fmt.Scan(&t1, &x1, &y1)
		if cannotArrive(t, x, y, t1, x1, y1) {
			success = false
			break
		}
		t = t1
		x = x1
		y = y1
	}

	if success {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}

}
