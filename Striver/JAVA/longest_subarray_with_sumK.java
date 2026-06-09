// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k.
// If no such sub-array exists, return 0.

// Look For Reference In the Book-2 On Pg No 135-136


import java.util.HashMap;

public class longest_subarray_with_sumK {
    public static int longest_subarray_with_sum_k(int[] arr, int k){
        int maxLen = 0;
        int prefixSum = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0;i<arr.length;i++){
            prefixSum+=arr[i];
            if(prefixSum==k){
                maxLen = Math.max(maxLen, i+1);
            }
            if(map.containsKey(prefixSum-k)){
                maxLen = Math.max(maxLen, i-map.get(prefixSum-k));
            }
            if(!map.containsKey(prefixSum)){
                map.put(prefixSum, i);
            }
        }
        return maxLen;
    }
    public static void main(String[] args) {
        int[] arr = {1, -1, 5, -2, 3};
        int k = 3;
        System.out.println("The Longest SubArray With Sum K Has Length : " + longest_subarray_with_sum_k(arr, k));
    }
}
