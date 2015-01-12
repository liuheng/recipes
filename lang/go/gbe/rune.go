package main

import "fmt"


func main() {

    var magic [3]byte
    magic[0] = 'x'

    var s [3]rune
    s[0] = '你'

    fmt.Println(magic)
    fmt.Println(s)
}
