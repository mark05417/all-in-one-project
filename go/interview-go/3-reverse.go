package main

import "fmt"

func main3() {
	fmt.Println(reverse("abcd"))
	fmt.Println(reverse("abcda"))
}
func reverse(s string) string {
	runes := []rune(s)
	l := len(runes)

	for i := 0; i < l/2; i++ {
		runes[i], runes[l-1-i] = runes[l-1-i], runes[i]
	}
	return string(runes)
}
