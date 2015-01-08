package main

import (
    "fmt"
    "os"
)

func main() {
    defer fmt.Println("defer fmt.Println will not be executed")
    os.Exit(123);
}
