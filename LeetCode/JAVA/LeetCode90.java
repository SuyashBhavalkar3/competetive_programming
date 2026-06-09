import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode90 {

    public static void recurseAndBacktrack(int idx, List<List<Integer>> allsets, List<Integer> currset, int[] nums){
        allsets.add(new ArrayList<>(currset));
        for(int i=idx;i<nums.length;i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            currset.add(nums[i]);
            recurseAndBacktrack(i+1, allsets, currset, nums);
            currset.remove(currset.size()-1);
        }
    }

    public static List<List<Integer>> findSubsets(int[] nums){
        Arrays.sort(nums);
        List<List<Integer>> allsets = new ArrayList<>();
        List<Integer> currset = new ArrayList<>();
        recurseAndBacktrack(0, allsets, currset, nums);
        return allsets;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 2};
        List<List<Integer>> res = findSubsets(nums);
        System.out.println(res);
    }
}
