package main

import "fmt"

func devide(a int, b int) (int, bool) {
    if b == 0 {
        return 0, false
    } else {
        return a/b, true
    }
}

func sum(params ... int) int {
    total := 0
    for _, num := range params {
        total += num
    }
    return total
}

func main(){
    a, b := devide(7, 3)
    fmt.Println(a, b)
    a, b = devide(7, 0)
    fmt.Println(a, b)

    fmt.Println(sum(1,2,3,4,5,6,7,8,9))
}
