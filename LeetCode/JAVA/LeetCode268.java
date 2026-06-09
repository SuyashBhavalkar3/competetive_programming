// Given an array nums containing n distinct numbers in the range [0, n],
// return the only number in the range that is missing from the array.

public class LeetCode268{
    public static int missing_Number(int[] arr){
        int n = arr.length;
        int maxSum = (n*(n+1))/2;
        for(int num : arr){
            maxSum-=num;
        }
        return maxSum;
    }
    public static void main(String[] args) {
        int[] arr = {9,6,4,2,3,5,7,0,1};
        System.out.println("Missing Number Is : " + missing_Number(arr));
    }
}