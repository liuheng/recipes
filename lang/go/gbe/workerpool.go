package main

import "fmt"
import "time"
import "math/rand"

type Worker struct {
    C chan string
}

func (w Worker) Run(c chan string, n int) {
    w.C = c
    s := fmt.Sprintf("worker %d is running", n)
    w.C <- s
    time.Sleep(time.Duration(rand.Intn(5)) * time.Second)

    s = fmt.Sprintf("worker %d done", n)
    w.C <- s
}

type Scheduler struct {
    C chan string
}

func (s Scheduler) Schedule(n int) {
    fmt.Println("now schedule work", n)
    w := Worker{make(chan string)}
    go w.Run(s.C, n)
}

func main(){
    rand.Seed(time.Now().UnixNano())
    c := make(chan string)
    s := Scheduler{c}
    for i := 0; i < 10; i++ {
        s.Schedule(i)
    }
    go func() {
        for msg := range c {
            fmt.Println(msg)
        }
    } ()

    var input string
    fmt.Scanln(&input)

}
