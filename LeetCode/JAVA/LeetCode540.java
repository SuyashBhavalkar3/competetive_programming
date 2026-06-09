// You are given a sorted array consisting of only integers where every element appears exactly twice,
// except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

// Look For Reference In the Book On Pg No 85-86



public class LeetCode540{
    public static int findSingle(int[] nums){
        int low = 0;
        int high = nums.length-1;
        while(low<high){
            int pivot = low + (high-low)/2;
            if(pivot%2==1)  pivot--;
            if(nums[pivot]==nums[pivot+1])  low = pivot+2;
            else    high = pivot;
        }
        return nums[low];
    }
    public static void main(String[] args){
        int[] nums = {1,1,2,3,3,4,4,8,8};
        int res = findSingle(nums);
        System.out.println(res);
    }
}