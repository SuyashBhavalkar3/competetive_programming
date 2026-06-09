// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Look For Reference In the Book-2 On Pg No 19


public class LeetCode53 {
    public static int max_sum_of_subarray(int[] arr){
        int max_sum = Integer.MIN_VALUE;
        int curr_sum = 0;
        for(int num : arr){
            curr_sum+=num;
            max_sum = Math.max(curr_sum, max_sum);
            if(curr_sum<0){
                curr_sum = 0;
            }
        }
        return max_sum;
    }

    public static void main(String[] args) {
        int[] arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println("Maximum Sum Of Continuous Subarray Is " + max_sum_of_subarray(arr));
    }
}
