package main

import (
    "fmt"
    "time"
)

func main(){
    p := fmt.Println

    p(time.Now().Unix())
    p(time.Now().UnixNano())

    now := time.Now()
    p(now)

    location, _ := time.LoadLocation("Asia/Shanghai")
    then := time.Date(2014, 12, 31, 23, 11, 11, 111111111, location)
    p(then)

    p(then.Year())
    p(then.Month())
    p(then.Minute())
    p(then.Second())
    p(then.Nanosecond())
    p(then.Location())

    p(then.Weekday())

    p(then.Before(now))
    p(then.Equal(now))
    p(then.After(now))

    diff := now.Sub(then)
    p(diff)
    p(diff.Hours())

    then = then.Add(diff)
    p(then)
    p(then.Equal(now))

}
