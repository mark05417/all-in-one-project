package main

import (
	"fmt"
)

type People interface {
	Show()
}

type Student struct{}

func (stu *Student) Show() {

}

func live() People {
	var stu *Student
	return stu
}

func live2() *Student {
	var stu *Student
	return stu
}

func main82() {
	if live() == nil {
		fmt.Println("AAAAAAA")
	} else {
		fmt.Println("BBBBBBB")
	}

	if live2() == nil {
		fmt.Println("CCCCCCC")
	} else {
		fmt.Println("DDDDDDD")
	}
}
