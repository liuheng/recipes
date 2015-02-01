package main

import (
    "fmt"
    // "reflect"
)

func main() {
    var structs = []struct{
        s string
        v int
    } {
        {"thomas", 1},
        {"alice", 2},
        {"agamemnon", 3},
    }
    for _, item := range(structs) {
        fmt.Println(item)
    }

}
