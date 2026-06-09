// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Look For Reference In the Book-2 On Pg No 110-111


import java.util.ArrayList;
import java.util.List;

public class LeetCode229 {
    public static List<Integer> majority_elementII(int[] nums){
        List<Integer> ans = new ArrayList<>();
        int cnt1 = 0, cnt2 = 0;
        int ele1 = Integer.MIN_VALUE;
        int ele2 = Integer.MIN_VALUE;
        for(int num : nums){
            if(cnt1==0 && num!=ele2){
                cnt1++;
                ele1 = num;
            }
            else if(cnt2==0 && num!=ele1){
                cnt2++;
                ele2 = num;
            }
            else if(num==ele1)  cnt1++;
            else if(num==ele2)  cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        int count1 = 0;
        int count2 = 0;
        for(int num:nums){
            if(num==ele1)   count1++;
            if(num==ele2)   count2++;
        }
        if(count1>nums.length/3)    ans.add(ele1);
        if(count2>nums.length/3)    ans.add(ele2);
        return ans;    
    }
    public static void main(String[] args) {
        int[] nums = {1, 2};
        System.out.println("Majority element is: "+majority_elementII(nums));
    }
}
