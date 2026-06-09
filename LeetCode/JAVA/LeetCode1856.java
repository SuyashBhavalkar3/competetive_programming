// The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

// For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
// Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums.
// Since the answer may be large, return it modulo 109 + 7.

// Note that the min-product should be maximized before performing the modulo operation.
// Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.

// A subarray is a contiguous part of an array.

// Look For Reference In the Book On Pg No 158-159


import java.util.Stack;

public class LeetCode1856{
    public static int previous_smaller(int[] arr){
        int n = arr.length;
        long[] prefix = new long[n+1];
        int[] left = new int[n];
        int[] right = new int[n];
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + arr[i];
        }
        Stack<Integer> monoSt = new Stack<>();
        for(int i=0;i<n;i++){
            while(!monoSt.empty() && arr[monoSt.peek()]>arr[i]){
                right[monoSt.pop()] = i;
            }
            if(monoSt.empty()){
                left[i] = -1;
            }
            else{
                left[i] = monoSt.peek();
            }
            monoSt.push(i);
        }
        while(!monoSt.empty()){
            right[monoSt.pop()] = n;
        }
        long ans = 0;
        for(int i=0;i<n;i++){
            int leftl = left[i]+1;
            int rightr = right[i];
            long sum = prefix[rightr]-prefix[leftl];
            ans = Math.max(ans, sum*arr[i]);
        }
        return (int)(ans%1_000_000_007);
    }
            //[0, 3, 4, 9, 15, 19, 21]
    public static void main(String[] args){
        int[] arr = {3,1,5,6,4,2};
        int res = previous_smaller(arr);
            System.out.print(res);
    }
}