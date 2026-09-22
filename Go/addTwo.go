package main
import "fmt"

func addTwo(a int, b int)int{
	return a+b;
}

func main(){
	fmt.Println(addTwo(2,3))
}