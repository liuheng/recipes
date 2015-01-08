package main

import (
    "fmt"
    "time"
)

func main(){
    p := fmt.Println

    t := time.Now()
    p(time.RFC3339)
    p(t.Format(time.RFC3339))

    t1, e := time.Parse(time.RFC3339, "2014-12-31T23:11:11+08:00")
    if e != nil {
        p(e)
    } else {
        p(t1)
    }

    p(t.Format("3:04PM"))
    p(t.Format("Mon Jan _2 15:04:05 2006"))
    p(t.Format("2006-01-02T15:04:05.999999-07:00"))

    ansic := "Mon Jan _2 15:04:05 2006"
    _, e = time.Parse(ansic, "8:41PM")
    p(e)
}
