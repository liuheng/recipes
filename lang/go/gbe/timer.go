package main

import "fmt"
import "time"

func testStoppedTimer(t2 * time.Timer) {
    <-t2.C
    fmt.Println("t2 is now closed, test the channel t2.C, should never return")
}

func myTimer() {
    t1 := time.NewTimer(2 * time.Second)
    t2 := time.NewTimer(5 * time.Second)
    <-t1.C
    fmt.Println("t1 expired, now I kill t2")
    s2 := t2.Stop()
    if s2 {
        fmt.Println("t2 is stopped")
    } else {
        fmt.Println("t2 is not stopped")
    }
    s3 := t2.Stop()
    if s3 {
        fmt.Println("t2 is stopped again")
    } else {
        fmt.Println("t2 has been expired or stopped already")
    }
    go testStoppedTimer(t2)
    t3 := time.NewTimer(5 * time.Second)
    <-t3.C
    fmt.Println("t3 expired, t2.C will never expire, please type to quit")
}

func main(){
    go myTimer()
    var ret string
    fmt.Scanln(&ret)
}
