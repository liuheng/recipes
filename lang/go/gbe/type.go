package main

import (
    "fmt"
)

type ITest interface {

}

type Test struct {
    value int
}

func checkType(i ITest){
    s, ok := i.(Test)
    fmt.Println("%s: %b", s, ok)
}

func main(){
    var t0 interface{} = Test{}

    var t1 interface{} = Test{}
    var t2 interface{} = Test{value: 5}
    var t3 interface{} = &Test{}
    var t4 interface{} = &Test{value: 5}

    s, ok := t0.(Test)
    fmt.Println("%s: %b", s, ok)

    fmt.Println(t1)
    checkType(t1)

    fmt.Println(t2)
    checkType(t2)

    fmt.Println(t3)
    checkType(t3)

    fmt.Println(t4)
    checkType(t4)

}
