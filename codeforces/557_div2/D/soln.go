package main

import "fmt"
import "bufio"
import "os"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func map_equals(a, b map[int]bool) bool {
	for k, v := range a {
		val, ok := b[k]
		if ok == false || val != v {
			return false
		}
	}
	return true
}

func z_algorithm(vals []map[int]bool) []int {
	z := make([]int, len(vals))
	var left, right int
	for i := 1; i < len(vals); i++ {
		if i <= right {
			z[i] = min(z[i-left], right-i+1)
		}
		for i+z[i] < len(vals) && map_equals(vals[z[i]], vals[i+z[i]]) {
			z[i]++
		}
		if i+z[i]-1 > right {
			left = i
			right = i + z[i] - 1
		}
	}
	return z
}

func main() {

	var reader *bufio.Reader = bufio.NewReader(os.Stdin)

	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)
	vals := make([]map[int]bool, n)
	for i := 0; i < n; i++ {
		vals[i] = make(map[int]bool)
	}
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Fscanf(reader, "%d %d\n", &a, &b)
		a--
		b--
		vals[a][(a-b+n)%n] = true
		vals[b][(b-a+n)%n] = true
	}
	for i := 0; i < n; i++ {
		vals = append(vals, vals[i])
	}
	z := z_algorithm(vals)
	//fmt.Printf("%v ", z)
	var res bool
	for i := 0; i < 2*n; i++ {
		if i != n && z[i] >= n {
			res = true
		}
	}
	if res {
		fmt.Print("Yes\n")
	} else {
		fmt.Print("No\n")
	}
}
