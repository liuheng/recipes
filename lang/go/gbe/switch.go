package main

import "fmt"
import "time"

func main(){
    i := 2
    switch i {
    case 1:
        fmt.Println("i is 1")
    case 2:
        fmt.Println("i is 2")
    case 3:
        fmt.Println("i is 3")
    }

    switch time.Now().Weekday() {
    case time.Saturday, time.Sunday:
        fmt.Println("it is the weekend")
    default:
        fmt.Println("it is a weekday")
    }

    t := time.Now()
    fmt.Println(t)
    switch {
    case t.Hour() < 12:
        fmt.Println("it is morning")
    case t.Hour() > 12:
        fmt.Println("it is afternoon")
    default:
        fmt.Println("it is noon")
    }
}
