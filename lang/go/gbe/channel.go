package main

import "fmt"
import "time"

func player(n string, c chan string, b bool) {
    if b {
        msg := "ping"
        fmt.Println(n, "send", msg)
        c <- "ping"
        for true {
            msg = <-c
            fmt.Println(n, "receive", msg)
            time.Sleep(1 * time.Second)
            msg = "ping"
            fmt.Println(n, "send", msg)
            c <- msg
        }
    } else {
        for true {
            msg := <-c
            fmt.Println(n, "receive", msg)
            time.Sleep(1 * time.Second)
            msg = "pong"
            fmt.Println(n, "send", msg)
            c <- msg
        }
    }
}

func main(){
    msg := make(chan string)
    go player("A", msg, true)
    go player("B", msg, false)

    var ret string
    fmt.Scanln(&ret)

}
