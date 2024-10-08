package main

import (
	"context"
	"fmt"
	"time"
)

func task(ctx context.Context) {
	select {
	case <-time.After(2 * time.Second):
		fmt.Println("Task completed")
	case <-ctx.Done(): // 任務取消或超時
		fmt.Println("Task cancelled:", ctx.Err())
	}
}

func main() {
	ctx, cancel := context.WithTimeout(context.Background(), 2*time.Second)
	defer cancel() // 確保取消函數在 main 結束時被調用

	go task(ctx)
	time.Sleep(3 * time.Second)
}
