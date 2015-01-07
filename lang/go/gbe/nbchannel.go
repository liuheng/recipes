package main

import "fmt"
import "math/rand"
import "time"

func sender(c1 chan bool, c2 chan string) {
    for true {
        n := rand.Intn(10)
        fmt.Println("get", n)
        if n/2 == 0 {
            c1 <- true
        } else {
            c2 <- "done"
        }
        time.Sleep(time.Duration(n) * time.Second)
    }
}

func main(){
    rand.Seed(time.Now().UnixNano())
    c1 := make(chan bool)
    c2 := make(chan string)
    go sender(c1, c2)

    for true {
        select {
        case msg := <-c1:
            fmt.Println("get result from c1", msg)
        case msg := <-c2:
            fmt.Println("get result from c2", msg)
        default:
            fmt.Println("no result")
        }
        time.Sleep(1 * time.Second)
    }

}
