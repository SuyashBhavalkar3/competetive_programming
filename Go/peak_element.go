package main
import "fmt";

func peakElement(nums []int) int{
	n := len(nums)
	if n==1{
		return 0
	}
	low := 0
	high := n-1
	for low<high {
		mid := low + (high - low)/2
		if nums[mid]<nums[mid+1] {
			low = mid+1
		} else{
			high = mid
		}
	}
	return low
}

func main(){
	nums := []int{1, 2, 1, 3, 5, 6, 4}
	peak := peakElement(nums)
	fmt.Println("The Peak Element Is : ", peak)
}