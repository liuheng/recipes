package main

import "fmt"
import "time"

func sender(c chan int) {
    for i := 0; i < 5; i++ {
        c <- i
        time.Sleep(1 * time.Second)
    }
    time.Sleep(1 * time.Second)
    close(c)
}

func main(){
    c := make(chan int)
    go sender(c)
    for e := range c {
        fmt.Println(e)
    }

}
