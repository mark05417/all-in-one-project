package main

// import (
// 	"encoding/json"
// 	"fmt"
// )

// type Param map[string]interface{}

// type Show struct {
// 	Param
// }

// type student struct {
// 	Name string
// }

// func zhoujielun(v interface{}) {
// 	switch msg := v.(type) {
// 	case student:
// 		println(msg.Name)
// 	default:
// 		println("default")
// 	}
// }

// type People struct {
// 	Name string `json:"ame"`
// }

// func (p *People) String() string {
// 	// return fmt.Sprintf("print: %v", p)

// 	// 使用 p.Name 而非 p 自身，避免遞迴調用 String() 方法
// 	return fmt.Sprintf("print: %s", p.Name)
// }

// func main7() {
// 	var s map[string]interface{}
// 	s = make(map[string]interface{})
// 	s["RMB"] = 10000

// 	s2 := make(map[string]interface{})
// 	s2["RMB"] = 10000

// 	println(s["RMB"] == s2["RMB"])

// 	s3 := new(Show)
// 	s3.Param = make(map[string]interface{})
// 	println(s3.Param["RMB"] == s2["RMB"])

// 	zhoujielun(s)
// 	zhoujielun(student{"zhoujielun"})

// 	js := `{
// 		"ame":"11"
// 	}`
// 	var p People
// 	err := json.Unmarshal([]byte(js), &p)
// 	if err != nil {
// 		fmt.Println("err: ", err)
// 		return
// 	}
// 	fmt.Println("people: ", p)

// 	fmt.Println(p.String())

// 	modifyMap()
// 	f2()
// }

// // Go 不允許直接對從 map 中取出的結構體進行字段修改。
// func modifyMap() {
// 	m := map[string]student{"people": {"zhoujielun"}}

// 	// m["people"].Name = "wuyanzu"

// 	tmp := m["people"]
// 	tmp.Name = "wuyanzu"
// 	m["people"] = tmp
// }

// type query func(string) string

// func exec(name string, vs ...query) string {
// 	ch := make(chan string)
// 	fn := func(i int) {
// 		ch <- vs[i](name)
// 	}
// 	for i, _ := range vs {
// 		go fn(i)
// 	}
// 	return <-ch
// }

// func f2() {
// 	ret := exec("111", func(n string) string {
// 		return n + "func1"
// 	}, func(n string) string {
// 		return n + "func2"
// 	}, func(n string) string {
// 		return n + "func3"
// 	}, func(n string) string {
// 		return n + "func4"
// 	})
// 	fmt.Println(ret)
// }
