// You are given an integer array nums of length n and an integer k.

// An element in nums is said to be qualified if there exist at least k elements in the array that are strictly greater than it.

// Return an integer denoting the total number of qualified elements in nums.

// Look For Reference In the Book-2 On Pg No 1


import java.util.Arrays;

public class LeetCode3759{
    public static int getK(int[] arr, int k){
        int[] distinct = Arrays.stream(arr).distinct().toArray();
        Arrays.sort(distinct);
        if(distinct.length-k<0)  return 0;
        return distinct.length-k;
    }
    public static void main(String[] args){
        int[] arr = {3,2,1};
        System.out.println(getK(arr, 1));
    }
}