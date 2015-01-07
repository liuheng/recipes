package main

import "fmt"
import "time"

func main(){
    tk := time.NewTicker(1 * time.Second)
    for t := range tk.C {
        fmt.Printf("do homework repeatly at %d, Ctrl+C to quit\n", t)
    }

}
