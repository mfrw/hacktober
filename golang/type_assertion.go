package main

import (
	"fmt"
	"log"
)

func main() {
	var foo interface{} = "hello"
	var bar interface{} = "world"

	f, ok := foo.(string)
	if !ok {
		log.Panicf("couldn't parse %s as string", foo)
	}

	b, ok := bar.(string)
	if !ok {
		log.Panicf("couldn't parse %s as string", bar)
	}

	// Protects agaisnt the panic, as foo is not an int
	_, ok = foo.(int)
	if ok {
		log.Panicf("expected 'ok' to be false, got true")
	}

	fmt.Println(f)
	fmt.Println(b)
}
