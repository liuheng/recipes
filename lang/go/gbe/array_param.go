package main

import (
    "fmt"
)

// [3]byte [2]byte []byte
// 如果位于形参位置，都是不同的的参数
// 数组都是值传递，没有指针退化一说
// 要传引用，用slice

func test_array(arr [3]byte) {
    fmt.Println("in test_array")
    fmt.Println(arr)
    arr[0] = 'g'
    fmt.Println(arr)
    fmt.Println("after test_array")
}

func test_array_by_slice(arr []byte) {
    arr[0] = 'g'
}

func main() {
    a := [3]byte{'a', 'b', 'c'}
    fmt.Println(a)
    test_array(a)
    fmt.Println(a)

    fmt.Println("---------------------")

    b := make([]byte, 3)
    b[0] = 'a'
    b[1] = 'b'
    b[2] = 'c'
    fmt.Println(b)
    test_array_by_slice(b)
    fmt.Println(b)
}
