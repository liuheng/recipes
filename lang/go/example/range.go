package main

import "fmt"

func main(){
    a := []int{1,2,3,4,5,6}
    sum := 0
    for i, v := range a {
        fmt.Println("index: ", i, " value: ", v)
        sum += v
    }

    m := map[string]string {"a": "apple", "b": "bnana"}
    for k, v := range m {
        fmt.Println("key: ", k, " value: ", v)
    }

    for _, c := range "hello world" {
        fmt.Println(string(c))
    }
}
