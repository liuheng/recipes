package main

import "fmt"

func main(){
    s := make([]string, 3, 3)
    fmt.Println(s)
    s[0] = "a"
    s[1] = "b"
    s[2] = "c"
    fmt.Println(s)

    s = append(s, "hello")
    fmt.Println(s)
    fmt.Println(s[2:4])

    a := make([][]int, 3)
    fmt.Println(a)
    for i:=0; i<3; i++ {
        length := i + 1
        a[i] = make([]int, length)
        for j:=0; j<length; j++ {
            a[i][j] = i + j
        }
    }
    fmt.Println(a)
}
