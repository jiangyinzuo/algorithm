package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var t int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &t)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	for i := 0; i < t; i++ {
		var n, c0, c1, h int
		fmt.Fscanf(reader, "%d %d %d %d\n", &n, &c0, &c1, &h)
		var s string
		fmt.Fscanf(reader, "%s\n", &s)
		oneCnt := 0
		zeroCnt := 0
		for j := range s {
			if s[j] == '1' {
				oneCnt++
			} else {
				zeroCnt++
			}
		}
		if h + c1 < c0 {
			c0 = h + c1
		} else if h + c0 < c1 {
			c1 = h + c0
		}
		fmt.Fprintf(writer,"%d\n", oneCnt * c1 + zeroCnt * c0)
	}
}
