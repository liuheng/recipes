package main

import (
    "fmt"
    "sync"
)

func SharedFunc1() {
    for i := 0; i < 26; i++ {
        fmt.Printf("%s", string(i + 65))
    }
    fmt.Printf("\n")
}

func SharedFunc2(mtx *sync.Mutex) {
    mtx.Lock()
    for i := 0; i < 26; i++ {
        fmt.Printf("%s", string(i + 65))
    }
    fmt.Printf("\n")
    mtx.Unlock()
}

func main(){
    for i := 0; i < 10; i++ {
        go func() {
            SharedFunc1()
        } ()
    }

    fmt.Println("---------------------------")
    var input string
    fmt.Scanln(&input)

    mtx := &sync.Mutex{}
    for i := 0; i < 10; i++ {
        go func() {
            SharedFunc2(mtx)
        } ()
    }

    fmt.Scanln(&input)
}
