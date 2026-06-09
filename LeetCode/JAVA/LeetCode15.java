// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.


// Look For Reference In the Book On Pg No 31-32



import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode15{
    public static List<List<Integer>> three_some(int[] nums){
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
            if(i>0 && nums[i]==nums[i-1])   continue;
            int j=i+1, k = nums.length-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0)   j++;
                else if(sum>0) k--;
                else{
                    ans.add(new ArrayList<>(List.of(nums[i], nums[j], nums[k])));
                    j++;    k--;
                    while(j<k && nums[j]==nums[j-1])    j++;
                    while(j<k && nums[k]==nums[k+1])    k--;
                }
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] arr = {-1, 0, 1, 2, -1, -4};
        List<List<Integer>> res = three_some(arr);
        System.out.println("The Number Of Triplets Formed Would Be : " + res);
    }
}