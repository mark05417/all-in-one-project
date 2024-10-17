package main

// func escapeDemo2_1() {
// 	// 8192 不會逃逸
// 	s := make([]int, 8192, 8192)
// 	for i := 0; i < len(s); i++ {
// 		s[i] = i
// 	}
// }

// func escapeDemo2_2() {
// 	// 8193 會逃逸
// 	s := make([]int, 8193, 8193)
// 	for i := 0; i < len(s); i++ {
// 		s[i] = i
// 	}
// }

func main() {
	x := 2
	square(x)

	x2 := 2
	square2(&x2)
}

func square(x int) *int {
	y := x * x
	return &y
}

func square2(x *int) {
	*x = *x * *x
}

// go run -gcflags=-m main.go
