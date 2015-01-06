package main

import "fmt"

func main(){
    var a [5] int
    fmt.Println(a)
    for i:=0; i<5; i++ {
        a[i] = i + 1
    }
    fmt.Println(a)

    var b [3][4] int
    fmt.Println(b)
    for i:=0; i<3; i++ {
        for j:=0; j<4; j++ {
            b[i][j] = 4 * i + j + 1
        }
    }
    fmt.Println(b)
}
