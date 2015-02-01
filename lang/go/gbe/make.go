package main

import (
    "fmt"
)

func main() {
    var buf []byte = []byte("hello world")
    fmt.Println(string(buf))
    buf[0] = 'g'
    buf[5] = '_'
    fmt.Println(string(buf))

    s := make([]byte, 3)
    s[0] = 'a'
    s[1] = 'b'
    s[2] = 'c'
    fmt.Println(s)
}
