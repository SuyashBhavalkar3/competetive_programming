// Given an array nums of n integers.

// Return the length of the longest sequence of consecutive integers.
// The integers in this sequence can appear in any order.

// Look For Reference In the Book-2 On Pg No 132-133


import java.util.HashSet;

public class longest_consecutive_sequence_in_array {
    public static int longest_sequence(int[] nums){
        if(nums==null||nums.length==0)  return 0;
        int longest = 1;
        HashSet<Integer> set = new HashSet<>();
        for(int num : nums){
            set.add(num);
        }
        for(int num : nums){
            if(!set.contains(num-1)){
                int cnt = 1;
                int curr = num;
                while(set.contains(curr+1)){
                    cnt++;
                    curr++;
                }
                longest = Math.max(cnt, longest);
            }
        }
        return longest;
    }
    public static void main(String[] args) {
        int[] arr = new int[]{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        System.out.println("The Longest Consecutive Sequence In Array Is : "+longest_sequence(arr));
    }
}
