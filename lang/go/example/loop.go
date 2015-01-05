package main

import "fmt"

func main(){
    i := 0
    for i < 5 {
        fmt.Println(i)
        i++
    }
    for j := 3; j < 10; j++ {
        fmt.Println(j)
    }
    for {
        fmt.Println("loop")
        if i >= 10 {
            break
        } else {
            i++
        }
    }
}
