package main

import "fmt"

func call(s string) {
    fmt.Println(s)
}

func main(){
    call("synchronously")

    go call("async 1")
    go call("async 2")

    go func(s string) {
        fmt.Println(s)
    } ("anonymous call asynchronously")

    var input string
    fmt.Scanln(&input)
    fmt.Println("done")
}
