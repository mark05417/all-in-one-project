package main

import "fmt"

func main4() {
	fmt.Println(reorder("abcd", "dacb"))
	fmt.Println(reorder("asdfasdf", "aswqwe"))
}
func reorder(s1, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}

	m := make(map[rune]int)
	for _, v := range s1 {
		m[v]++
	}
	for _, v := range s2 {
		m[v]--
		if m[v] < 0 {
			return false
		}
	}
	return true
}
