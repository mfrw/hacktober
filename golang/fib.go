package main

import "fmt"

func fib() func() int {
	x, y := 0, 1
	return func() int {
		x, y = y, x+y
		return x
	}
}

func main() {
	f := fib()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
