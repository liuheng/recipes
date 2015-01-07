package main

import "fmt"
import "time"
import "math/rand"

func main(){
    rand.Seed(time.Now().UnixNano())
    c1 := make(chan string)
    c2 := make(chan string)

    go func() {
        for true {
            fmt.Println("f1 called")
            time.Sleep(time.Duration(rand.Intn(5)) * time.Second)
            c1 <- "f1 done"
        }
    }()
    go func() {
        for true {
            fmt.Println("f2 called")
            time.Sleep(time.Duration(rand.Intn(5)) * time.Second)
            c2 <- "f2 done"
        }
    }()

    for true {
        select {
        case msg1 := <-c1:
            fmt.Println("return from f1,", msg1)
        case msg2 := <-c2:
            fmt.Println("return from f2,", msg2)
        case <-time.After(2 * time.Second):
            fmt.Println("timeout")
        }
    }

}
