package main

import (
    "fmt"
)

const (
    _ = iota
    KB int64 = 1 << (10 * iota)
    MB
    GB
    TB
)

const (
    a = 100 + iota
    b
    c
    d
    e
)

func main() {
    fmt.Println(KB)
    fmt.Println(MB)
    fmt.Println(GB)
    fmt.Println(TB)
    fmt.Println(a)
    fmt.Println(b)
    fmt.Println(c)
    fmt.Println(d)
    fmt.Println(e)
}
