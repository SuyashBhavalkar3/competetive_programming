import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class subset_sums{
    public static void helper(int index, int sum, int N, int[] num, List<Integer> subset){
        if(index==N){
            subset.add(sum);
            return;
        }
        helper(index+1, sum+num[index], N, num, subset);
        helper(index+1, sum, N, num, subset);
    }
    public static List<Integer> subsets(int[] nums){
        List<Integer> subset = new ArrayList<>();
        helper(0, 0, nums.length, nums, subset);
        Collections.sort(subset);
        return subset;
    }
    public static void main(String[] args) {
        int[] nums = {1, 2, 7, 3};
        List<Integer> subsets_sum = subsets(nums);
        System.out.println(subsets_sum);
    }
}