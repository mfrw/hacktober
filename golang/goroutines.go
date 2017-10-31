package main

import "fmt"

func myFunction(from string) {
	for i := 0; i < 3; i++ {
		fmt.Println(from, ":", i)
	}
}

func main() {

	// Synchronous call of myFunction
	myFunction("synchronous")

	// Goroutine call of myFunction
	go myFunction("goroutine")

	// Goroutine for an anonymous function call
	go func(msg string) {
		fmt.Println(msg)
	}("goroutine anonymous")

	var input string
	// `Scanln` code requires we press a key before the program exits
	fmt.Scanln(&input)
	fmt.Println("done")

}
