package main

import (
    "fmt"
    "os"
    "os/signal"
    "syscall"
)

func main(){
    sig := make(chan os.Signal, 1)
    done := make(chan bool, 1)

    signal.Notify(sig, syscall.SIGINT, syscall.SIGTERM)
    go func() {
        s := <-sig
        fmt.Println()
        fmt.Println(s)
        done <- true
    } ()

    fmt.Println("awaiting for SIGINT")
    <-done
    fmt.Println("exiting")
}
