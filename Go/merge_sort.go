package main

import "fmt"

func mergeArr(nums []int, low int, pivot int, high int){
	l1 := pivot-low+1
	r1 := high-pivot
	leftSubArr := make([]int, l1)
	rightSubArr := make([]int, r1)
	for i:=0;i<l1;i++ {
		leftSubArr[i] = nums[low+i]
	}
	for i:=0;i<r1;i++ {
		rightSubArr[i] = nums[pivot+i+1]
	}
	i:=0; j:=0; k:=low
	for i<l1 && j<r1 {
		if(leftSubArr[i]<=rightSubArr[j]){
			nums[k] = leftSubArr[i]
			i++
		} else{
			nums[k] = rightSubArr[j]
			j++
		}
		k++
	}
	for i<l1 {
		nums[k] = leftSubArr[i]
		i++
		k++
	}
	for j<r1 {
		nums[k] = rightSubArr[j]
		j++
		k++
	}
}

func merge_sort(nums []int, low int, high int){
	if low>=high{
		return
	}
	pivot := low + (high - low)/2
	merge_sort(nums, low, pivot)
	merge_sort(nums, pivot+1, high)
	mergeArr(nums, low, pivot, high)
}

func main() {
	nums:=[]int{38, 27, 43, 3, 9, 82, 10}
	merge_sort(nums, 0, len(nums)-1)
	for _, num:= range nums{
		fmt.Print(num, " ")
	}
}
