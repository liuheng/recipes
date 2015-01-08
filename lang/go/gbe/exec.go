package main

import (
    "syscall"
    "os"
    "os/exec"
)

func main(){
    bin, err := exec.LookPath("ls")
    if err != nil {
        panic(err)
    }

    args := []string{"ls", "-a", "-l", "-h"}

    env := os.Environ()

    err = syscall.Exec(bin, args, env)
    if err != nil {
        panic(err)
    }
}
