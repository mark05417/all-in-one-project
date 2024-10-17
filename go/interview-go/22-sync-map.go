package main

import (
	"fmt"
	"sync"
)

func main22() {
	var m sync.Map
	m.Store("address", map[string]string{"province": "江苏", "city": "南京"})
	v, _ := m.Load("address")

	// fmt.Println(v["province"])
	fmt.Println(v.(map[string]string)["city"])
	fmt.Println(v.(map[string]string)["province"])
}
