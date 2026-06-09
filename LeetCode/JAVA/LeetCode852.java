// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

// Look For Reference In the Book On Pg No 44-45


public class LeetCode852{
    public static int binarySearchPeak(int[] arr){
        int low=0;
        int high=arr.length-1;
        while(low<high){
            int pivot = low + (high - low)/2;
            if(arr[pivot]<arr[pivot+1]){
                low=pivot+1;
            }
            else{
                high=pivot;
            }
        }
        return low;
    }
    public static void main(String[] args) {
        int[] arr = new int[]{4, 5, 3, 2, 1};
        for (int num : arr){
            System.out.println(num);
        }
        int res = binarySearchPeak(arr);
        System.out.println("Peek Element Is : "+arr[res]);
    }
}