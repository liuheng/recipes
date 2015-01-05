package main

import "fmt"

func main(){
    m := make(map[string] int)
    m["k1"] = 1
    m["k2"] = 2

    fmt.Println(m)
    delete(m, "k2")

    _, err := m["k1"]
    fmt.Println(err)
    fmt.Println(m["k1"])
    _, err = m["k2"]
    fmt.Println(err)
    fmt.Println(m["k2"])

    n := map[string] int {"k1": 1, "k2": 2}
    fmt.Println(n)
}
