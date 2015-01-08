package main

import (
    "fmt"
    "net/url"
    "strings"
)

func main(){
    // s := "postgres://user:pass@host.com:5432/path?k=v#f"
    s := "mysql://thomas:sqlscript01@claudiuscivilis.com:8897/sampledb?k=v#p"
    // s := "https://www.claudiuscivilis.com:8897/sampledb?k=v#p"

    u, err := url.Parse(s)
    if err != nil {
        panic(err)
    }


    fmt.Println(u.User)
    if u.User != nil {
        fmt.Println(u.Scheme)
        fmt.Println(u.User.Username())
        p, _ := u.User.Password()
        fmt.Println(p)
    }

    fmt.Println(u.Host)
    h := strings.Split(u.Host, ":")
    fmt.Println(h[0])
    fmt.Println(h[1])

    fmt.Println(u.Path)
    fmt.Println(u.Fragment)

    fmt.Println(u.RawQuery)
    m, _ := url.ParseQuery(u.RawQuery)
    fmt.Println(m)
    fmt.Println(m["k"][0])

}
