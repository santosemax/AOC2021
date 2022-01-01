package main

import (
	"io/ioutil"
	"log"
	"strings"
)

const ArraySize = 12
const Total = 1000

func main() {

	content, err := ioutil.ReadFile("data.txt")

	if err != nil {
		log.Fatal(err)
	}

	lines := strings.Split(string(content), "\n")

	// Debug
	//for i := 0; i < Total; i++ {
	//	fmt.Println(lines[i])
	//}

}
