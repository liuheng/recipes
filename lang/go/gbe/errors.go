package main

import "fmt"
import "errors"

type argError struct {
    arg int
    prob string
}

func (a argError) Error() (string) {
    return fmt.Sprintf("%d - %s", a.arg, a.prob)
}

func f1(value int) (int, error) {
    if value == 9 {
        return -1, errors.New("invalid argument")
    }
    return value, nil
}

func f2(value int) (int, error) {
    if value == 9 {
        return -1, &argError{value, "invalid argument"}
    }
    return value, nil
}

func main(){
    var a [6] int
    for i:=7; i<13; i++ {
        a[i-7] = i
    }
    fmt.Println(a)
    for k, i := range(a) {
        fmt.Printf("processing %d - %d\n", k, i)
        if r, e := f1(i); e != nil {
            fmt.Println("f1 failed with", e)
        } else {
            fmt.Println("f1 worked with", r)
        }

        if r, e := f2(i); e != nil {
            fmt.Println("f1 failed with", e)
        } else {
            fmt.Println("f1 worked with", r)
        }
    }
}
