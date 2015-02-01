package main

import (
    "fmt"
)

// in main before test
// in test before panic
// in defer before panic
// in defer before recover
// panic in defer
// in defer after recover
// in main after test

// 延迟调⽤用中引发的错误,可被后续延迟调⽤用捕获,但仅最后⼀一个错误可被捕获

func test() {
    defer func() {
        fmt.Println("in defer before recover") // 4
        fmt.Println(recover())
        fmt.Println("in defer after recover") // 6
    }()

    defer func() {
        fmt.Println("in defer before panic") // 3
        panic("panic in defer") // 5
        fmt.Println("in defer after panic")
    }()

    fmt.Println("in test before panic") // 2
    panic("panic in test")
    fmt.Println("in test after panic")
}

func main() {
    fmt.Println("in main before test") // 1
    test()
    fmt.Println("in main after test") // 7
}
