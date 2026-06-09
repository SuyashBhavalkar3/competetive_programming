// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Look For Reference In the Book On Pg No 61-62-63




import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;


public class LeetCode40 {

    public static void helper(int[] candidates, int target, int start, List<Integer> temp, List<List<Integer>> result){
        if (target == 0){
            result.add(new ArrayList<>(temp));
        }
        if (target<0)   return;
        for(int i=start;i<candidates.length;i++){
            if(i>start && (candidates[i]==candidates[i-1])) continue;
            if(candidates[i]>target)    break;
            temp.add(candidates[i]);
            helper(candidates, target-candidates[i], i+1, temp, result);
            temp.remove(temp.size()-1);
        }
    }
    public static List<List<Integer>> findCombination2(int[] candidates, int target){
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        helper(candidates, target, 0, new ArrayList<>(), res);
        return res;
    }
    public static void main(String[] args) {
        int[] candidates = {1, 1, 2, 5, 6, 7, 10};
        int target = 8;
        List<List<Integer>> result = findCombination2(candidates, target);
        System.out.println(result);
    }
}