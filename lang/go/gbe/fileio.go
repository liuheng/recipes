package main

import (
    "fmt"
    "bufio"
    "io"
    "io/ioutil"
    "os"
)

func testRead() {
    dat, err := ioutil.ReadFile("./test.dat")
    if err == nil {
        fmt.Printf("%s\n", string(dat))
    }

    f, err := os.Open("./test.dat")
    if err != nil {
        panic(err)
    }
    defer f.Close()

    b1 := make([]byte, 5)
    f.Seek(6, 0)
    f.Read(b1)
    fmt.Printf("%s\n", string(b1))

    r := bufio.NewReader(f)
    b2, _ := r.Peek(5)
    fmt.Printf("%s\n", string(b2))

    f.Seek(6, 0)
    b3 := make([]byte, 5)
    _, err = io.ReadAtLeast(f, b3, 5)
    if err != nil {
        fmt.Println(err)
    } else {
        fmt.Printf("%s\n", string(b3))
    }
}

func testWrite() {
    d1 := []byte("hello\nworld\n")
    ioutil.WriteFile("./test1.dat", d1, 0644)

    f, _ := os.Create("./test.dat")
    defer f.Close()

    d2 := []byte("abcdefghijklmnopqrstuvwxyz")
    f.Write(d2)
    f.WriteString("1234567890")
    f.Sync()

    f1, _ := os.Create("./test2.dat")
    defer f1.Close()
    w := bufio.NewWriter(f1)
    w.WriteString("test buffer io write")
    w.Flush()

}

func main(){
    testWrite()
    testRead()
}
