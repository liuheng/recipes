package main

import (
    "fmt"
    "os"
    "github.com/codegangsta/cli"
)

func main() {
    app := cli.NewApp()
    app.Name = "boom"
    app.Usage = "make an explosive entrance"

    app.Flags = []cli.Flag {
        cli.StringFlag{
            Name: "lang, l",
            Value: "english",
            Usage: "language for greeting",
        },
    }

    app.Action = func(c *cli.Context) {
        name := "someone"
        if len(c.Args()) > 0 {
            name = c.Args()[0]
        }
        if c.String("lang") == "spanish" {
            println("Hola", name)
        } else {
            println("Hello", name)
        }
    }

    var tasks = []string{"cook", "clean", "laundry", "eat", "sleep", "code"}
    app.EnableBashCompletion = true
    app.Commands = []cli.Command{
      {
        Name:      "add",
        ShortName: "a",
        Usage:     "add a task to the list",
        Action: func(c *cli.Context) {
          println("added task: ", c.Args().First())
        },
      },
      {
        Name:      "complete",
        ShortName: "c",
        Usage:     "complete a task on the list",
        Action: func(c *cli.Context) {
          println("completed task: ", c.Args().First())
        },
        BashComplete: func(c *cli.Context) {
          // This will complete if no args are passed
          if len(c.Args()) > 0 {
            return
          }
          for _, t := range tasks {
            fmt.Println(t)
          }
        },
      },
      {
        Name:      "template",
        ShortName: "r",
        Usage:     "options for task templates",
        Subcommands: []cli.Command{
          {
            Name:  "add",
            Usage: "add a new template",
            Action: func(c *cli.Context) {
                println("new task template: ", c.Args().First())
            },
          },
          {
            Name:  "remove",
            Usage: "remove an existing template",
            Action: func(c *cli.Context) {
              println("removed task template: ", c.Args().First())
            },
          },
        },
      },
    }

    app.Run(os.Args)
}
