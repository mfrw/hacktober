package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

const (
	WRITE_ROUTINE_COUNT = 10
	READ_ROUTINE_COUNT  = 10
	MAP_SIZE            = 20
)

// Simulating reads and writes from different routines to a single map by locking the result map
func main() {
	var mutex = &sync.Mutex{}
	var resource = make(map[int]int)

	// Initializes map with 20 entries
	for key := 0; key < MAP_SIZE; key++ {
		resource[key] = 0
	}

	// Start write routines
	for writeIdx := 0; writeIdx < WRITE_ROUTINE_COUNT; writeIdx++ {
		go func() {
			for {
				// Generate random key based on the map size
				key := rand.Intn(MAP_SIZE)
				// Generate random values
				val := rand.Intn(1000)

				// Lock before writing to map
				mutex.Lock()
				// Set/write map value
				resource[key] = val
				fmt.Printf("set map[%d] = %d\n", key, val)
				// Unlock after write
				mutex.Unlock()

				// Simulate longer processing time
				time.Sleep(time.Millisecond)
			}
		}()
	}

	// Start read routines
	for readIdx := 0; readIdx < READ_ROUTINE_COUNT; readIdx++ {
		go func() {
			for {
				// Generate random key based on the map size
				key := rand.Intn(MAP_SIZE)

				// Lock before writing to map
				mutex.Lock()
				// Read map value
				val := resource[key]
				fmt.Printf("get map[%d] = %d\n", key, val)
				// Unlock after write
				mutex.Unlock()

				time.Sleep(time.Millisecond)
			}
		}()
	}

	// Allow the read/write routines to work for 2 seconds
	time.Sleep(1 * time.Second)

	// Print out final resource before exiting
	fmt.Println("\nCurrent resource values:")
	mutex.Lock()
	for idx := 0; idx < MAP_SIZE; idx++ {
		fmt.Printf("map[%d]=%d\n", idx, resource[idx])
	}
	mutex.Unlock()
}
