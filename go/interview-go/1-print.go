package main

import (
	"fmt"
)

func main1() {
	number := make(chan bool)
	letter := make(chan bool)
	done := make(chan bool)

	go func() {
		i := 1
		for {
			select {
			case <-number:
				if i > 28 {
					done <- true
					return
				}
				fmt.Printf("%d", i)
				i++
				fmt.Printf("%d", i)
				i++
				letter <- true
			}
		}
	}()

	go func() {
		j := 'A'
		for {
			select {
			case <-letter:
				if j > 'Z' {
					done <- true
					return
				}
				fmt.Printf("%c", j)
				j++
				fmt.Printf("%c", j)
				j++
				number <- true
			}
		}
	}()

	number <- true

	<-done
	fmt.Println("\nMain done")
}
