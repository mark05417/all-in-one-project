package main

import (
	"fmt"
	"math/rand"
)

func main9() {
	out := make(chan int)
	done := make(chan bool, 1)
	// wg := sync.WaitGroup{}
	// wg.Add(2)

	go func() {
		// defer wg.Done()
		for i := 0; i < 5; i++ {
			out <- rand.Intn(100)
		}
		close(out)
	}()
	go func() {
		// defer wg.Done()
		for i := range out {
			fmt.Println(i)
		}
		done <- true
	}()
	// wg.Wait()
	<-done
}
