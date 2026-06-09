// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.


// Look For Reference In the Book On Pg No 69-70

public class LeetCode136 {
    public static int findSingle(int[] nums){
        int res = 0;
        for(int num : nums){
            res^= num;
        }
        return res;
    }
    public static void main(String[] args) {
        int[] nums = {2,2,3,3,4};
        if(findSingle(nums)!=0){
        System.out.println("The Only Single Number Is : " + findSingle(nums));
        }
        else{
            System.out.println("There Is No Single Element In nums array");
        }
    }
}
