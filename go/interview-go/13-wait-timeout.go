package main

import (
	"fmt"
	"sync"
	"time"
)

func main13() {
	wg := sync.WaitGroup{}
	c := make(chan struct{})
	for i := 0; i < 10; i++ {
		wg.Add(1)
		go func(num int, close <-chan struct{}) {
			defer wg.Done()
			<-close
			fmt.Println(num)
		}(i, c)
	}

	if WaitTimeout(&wg, time.Second*5) {
		close(c)
		fmt.Println("timeout exit")
	}
	time.Sleep(time.Second * 10)
}

func WaitTimeout(wg *sync.WaitGroup, timeout time.Duration) bool {
	// 使用帶有緩衝區的 channel 來避免競爭條件
	ch := make(chan bool, 1)

	// 啟動一個計時器來處理超時
	go func() {
		time.AfterFunc(timeout, func() {
			ch <- true
		})
	}()

	// 等待 WaitGroup 結束
	go func() {
		wg.Wait()
		ch <- false
	}()

	return <-ch
}
