// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
// return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array,
// which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

// Look For Reference In the Book On Pg No 137



import java.util.Arrays;
import java.util.Stack;

public class LeetCode503 {
    public static int[] next_greater(int[] nums){
        int[] res = new int[nums.length];
        Stack<Integer> monoSt = new Stack<>();
        Arrays.fill(res, -1);
        for(int i=0;i<2*nums.length;i++){
            int current = nums[i%nums.length];
            while(!monoSt.empty()&&nums[monoSt.peek()]<current){
                res[monoSt.pop()] = current;
            }
            if(i<nums.length){
                monoSt.push(i);
            }
        }
        return res;
    }
    public static void main(String[] args){
        int[] nums = {1,2,3,4,3};
        for(int num : next_greater(nums)){
            System.out.print(num+" ");
        }
    }
}
