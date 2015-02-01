package main

import (
    "fmt"
    "sync"
    "time"
)

type Guard struct {
    sync.Mutex
    n int
}

func SyncCall(g *Guard, i int) {
    for {
        g.Lock()
        g.n++
        fmt.Println("SyncCall", i, "is calling")
        time.Sleep(1 * time.Second)
        g.Unlock()
        time.Sleep(1 * time.Second)
    }
}

func main() {
    g := Guard{}
    go SyncCall(&g, 1)
    go SyncCall(&g, 2)
    go SyncCall(&g, 3)
    fmt.Scanln()
}
