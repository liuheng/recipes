package main

import "fmt"

func byvalue(a int) {
    a = 5
}

//invalid syntax
//func byref(a &int) {
//    a = 5
//}

func bypointer(a *int) {
    *a = 5
}

func main(){
    a := 3
    byvalue(a)
    fmt.Println(a)
    a = 3
    bypointer(&a)
    fmt.Println(a)
    fmt.Println(&a)
}
