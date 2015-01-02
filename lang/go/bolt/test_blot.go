package main

import (
    "encoding/json"
    "fmt"
    "log"
    "time"
    "github.com/boltdb/bolt"
)

type Post struct{
    Created time.Time
    Title string
    Content string
}

func main() {
    db, err := bolt.Open("blog.db", 0600, nil)
    if err != nil {
        log.Fatal(err)
    }

    db.Update(func(tx *bolt.Tx) error {
        b, err := tx.CreateBucketIfNotExists([]byte("posts"))
        if err != nil {
            return err
        }
        return b.Put([]byte("2015-01-01"), []byte("My New Year Post"))
    })

    db.View(func(tx *bolt.Tx) error {
        b := tx.Bucket([]byte("posts"))
        v := b.Get([]byte("2015-01-01"))
        fmt.Printf("%s\n", v)
        return nil
    })

    post := &Post{
        Created: time.Now(),
        Title: "My first post",
        Content: "Hello, this is my first post.",
    }

    db.Update(func(tx *bolt.Tx) error {
        b, err := tx.CreateBucketIfNotExists([]byte("posts"))
        if err != nil {
            return err
        }
        encoded, err := json.Marshal(post)
        if err != nil {
            return err
        }
        return b.Put([]byte(post.Created.Format(time.RFC3339)), encoded)
    })

    db.View(func(tx *bolt.Tx) error {
        b := tx.Bucket([]byte("posts"))
        v := b.Get([]byte(post.Created.Format(time.RFC3339)))
        var decoded map[string] interface{}
        err := json.Unmarshal(v, &decoded)
        if err != nil {
            return err
        }
        fmt.Printf("Title: %s\n", decoded["Title"])
        fmt.Printf("Content: %s\n", decoded["Content"])
        fmt.Printf("Created: %s\n", decoded["Created"])
        return nil
    })

    defer db.Close()
}
