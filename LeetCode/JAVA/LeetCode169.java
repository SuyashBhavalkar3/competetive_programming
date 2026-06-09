// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.

// Look For Reference In the Book On Pg No 22

import java.util.HashMap;
import java.util.Scanner;

public class LeetCode169 {
    public static int findMajorityElement(int[] nums){
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            freqMap.put(nums[i], freqMap.getOrDefault(nums[i], 0)+1);
            if(freqMap.get(nums[i])>n/2){
                return nums[i];
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter Limit Of Array : ");
            int limit = sc.nextInt();
            int[] arr = new int[limit];
            System.out.println("Enter Elements : ");
            for(int i=0;i<limit;i++){
                arr[i] = sc.nextInt();
            }
            int re = findMajorityElement(arr);
            if(re!=-1)
            System.out.println("Majority Element Is : "+re);
            else
            System.out.println("NO Majority Element FOund.");
        }
    }
}
