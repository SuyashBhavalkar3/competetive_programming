// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


// Look For Reference In the Book On Pg No 33-34-35


import java.util.ArrayList;
import java.util.List;

public class LeetCode39{
    public static void backtrack(int[] candidates, int target, int start, List<Integer> comb, List<List<Integer>> res){
        if(target==0){
            res.add(new ArrayList<>(comb));
        }
        if(target<0){
            return;
        }
        for(int i=start;i<candidates.length;i++){
            comb.add(candidates[i]);
            backtrack(candidates, target-candidates[i], i, comb, res);
            comb.remove(comb.size()-1);
        }
    }
    public static List<List<Integer>> findCombination(int[] candidates, int target){
        List<List<Integer>> result = new ArrayList<>();
        backtrack(candidates, target, 0, new ArrayList<>(), result);
        return result;
    }
    public static void main(String[] args) {
        int[] candidates = {2, 3, 5};
        int target = 8;
        List<List<Integer>> res = findCombination(candidates, target);
        System.out.println(res);
    }
}