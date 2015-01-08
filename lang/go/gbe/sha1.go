package main

import (
    "fmt"
    "crypto/sha1"
)

func main(){
    s := "I will sha1 this string"
    h := sha1.New()

    fmt.Println(h)
    h.Write([]byte(s))
    fmt.Println(h)
    bs := h.Sum(nil)
    fmt.Println(h)

    fmt.Println(s)
    fmt.Printf("%x\n", bs)
}
