package main

import (
	"fmt"
	"math"
	"sync"
)

// worker is an example of worker that count x^2 and put it into receiving-only channel
func worker(input float64, resultChan chan<- float64) {
	// return input^2
	resultChan <- math.Pow(input, 2)
}

// This example will wait for result being processed before calling waitgroup.Done() to ensure not only that
// all worker is done, but also result of the work has been processed in the case that
// aggregation of results are needed
func main() {
	var wg sync.WaitGroup
	// Define the work array
	workQueue := []float64{20, 40, 60, 80, 100}

	// Add count of work to be done to work group (not considering upper bound, etc)
	workCount := len(workQueue)
	wg.Add(workCount)

	// Define buffered result channel with size of work count
	resultChan := make(chan float64, workCount)
	defer close(resultChan)

	// Define a done channel
	done := make(chan bool, 1)
	defer close(done)

	// Spawn a wait in a separate routine to monitor for completion of wait group
	go func() {
		wg.Wait()
		done <- true
	}()

	// Loop through and spawn off workers
	for _, work := range workQueue {
		go worker(work, resultChan)
	}

	// Wait for result channel to receive all expected results and exit
	var currentTotal float64

	for {
		select {
		case result := <-resultChan:
			// select case to receive results
			newTotal := currentTotal + result
			fmt.Printf("Result received: %f [total= %f + %f = %f]\n", result, currentTotal, result, newTotal)
			currentTotal = newTotal
			// indicate that a result has been processed/aggregated
			wg.Done()
		case <-done:
			// select case that all result is done (see line 35 where done bool is sent)
			fmt.Printf("All results has been received total is %f, now exitting...\n", currentTotal)
			return
		}
	}
}
