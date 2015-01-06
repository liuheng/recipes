package main

import "fmt"
import "math"

type shape interface {
    area() float64
    perim() float64
}

type square struct {
    width, height float64
}

type circle struct {
    radius float64
}

func (s square) area() float64 {
    return s.width * s.height
}

func (s square) perim() float64 {
    return 2 * s.width + 2 * s.height
}

func (s circle) area() float64 {
    return math.Pi * s.radius * s.radius
}

func (s circle) perim() float64 {
    return 2 * math.Pi * s.radius
}

func measure(g shape) {
    fmt.Println(g)
    fmt.Println(g.area())
    fmt.Println(g.perim())
}

func main(){
    s := square{width: 3, height: 4}
    c := circle{radius: 5}

    measure(s)
    measure(c)
}
