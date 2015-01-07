package main

import (
    "fmt"
    "os"
)

func clean(n int) {
    fmt.Println("do something clean in", n)
}

func f4() {
    defer clean(4)
    _, err := os.Create("/tmp/file")
    if err != nil {
        panic(err)
    }
}

func f3() {
    defer clean(3)
    f4()
}

func f2() {
    defer clean(2)
    f3()
}

func f1() {
    defer clean(1)
    f2()
}

func main(){
    defer clean(0)
    f1()
}
