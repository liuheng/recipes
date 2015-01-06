package main

import "fmt"

func getOp(op string) func(int, int) int {
    switch op{
    case "+":
        return func(a int,b int) int{
            return a + b
        }
    case "-":
        return func(a int,b int) int{
            return a - b
        }
    case "*":
        return func(a int,b int) int{
            return a * b
        }
    case "/":
        return func(a int,b int) int{
            return a / b
        }
    }
    return func(a int, b int) int{
        fmt.Println("invalid operation")
        return 0
    }
}


func main(){
    fmt.Println(getOp("+")(3, 4))
    fmt.Println(getOp("-")(3, 4))
    fmt.Println(getOp("*")(3, 4))
    fmt.Println(getOp("/")(3, 4))
    fmt.Println(getOp("x")(3, 4))
}
