package main

import (
    "fmt"
)

func main(){
    var a, b int
    a = 4
    b = 3
    fmt.Println(a/b)
    fmt.Println(float64(a/b))
    fmt.Println(float64(a)/float64(b))
}
