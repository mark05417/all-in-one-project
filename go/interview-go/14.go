package main

import (
	"fmt"
)

type Student2 struct {
	Age int
}

func main14() {
	kv := map[string]Student2{"menglu": {Age: 21}}
	data, ok := kv["menglu"]
	data.Age = 22
	kv["menglu"] = data

	fmt.Println(ok)
	s := []Student2{{Age: 21}}
	s[0].Age = 22
	fmt.Println(kv, s)
}
