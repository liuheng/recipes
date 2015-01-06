package main

import "fmt"

type person struct {
    name string
    age int
}

func (p person) welcome() {
    fmt.Println("My name is", p.name, "I am", p.age)
}

func main(){
    fmt.Println(person{"Bob", 20})
    fmt.Println(person{name: "Bob", age: 20})
    fmt.Println(person{name: "Fred"})
    fmt.Println(&person{name: "Ann", age: 40})

    s := person{name: "Thomas", age: 28}
    fmt.Println(s.name)

    sp := &s
    fmt.Println(&sp)
    fmt.Println(sp.age)

    s.welcome()

    sp.age = 29
    fmt.Println(sp.age)
    fmt.Println(s.age)
}
