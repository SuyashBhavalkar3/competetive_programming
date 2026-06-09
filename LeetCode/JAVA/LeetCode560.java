// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Look For Reference In the Book-2 On Pg No 140 - 141


import java.util.HashMap;

public class LeetCode560 {
    public static int count_subarrays_with_sum_k(int[] nums, int k){
        int count = 0;
        int prefixSum = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        for(int i=0;i<nums.length;i++){
            prefixSum+=nums[i];
            if(map.containsKey(prefixSum-k)){
                count+=map.get(prefixSum-k);
            }
            map.put(prefixSum, map.getOrDefault(prefixSum, 0)+1);
        }
        return count;
    }
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
        int k = 3;
        int result = count_subarrays_with_sum_k(nums, k);
        System.out.println("Number of subarrays with sum " + k + ": " + result);
    }
}
