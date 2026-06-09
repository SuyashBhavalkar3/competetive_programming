// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Look For Reference In the Book-2 On Pg No 50-51


import java.util.*;

public class LeetCode18 {
    public static List<List<Integer>> fourSum(int[] nums, int target){
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])   continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1, l=n-1;
                while(k<l){
                    int sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum<target)  k++;
                    else if(sum>target) l--;
                    else{
                        ans.add(Arrays.asList(nums[i], nums[j], nums[k], nums[l]));
                        k++;    l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1])    l--;
                    }
                }
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] nums = {-1,0,1,2,-1,-4};
        int target = 0;
        List<List<Integer>> res = fourSum(nums, target);
        System.out.println(res);
    }
}
