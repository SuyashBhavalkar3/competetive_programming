// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Look For Reference In the Book-3 On Pg No 62-63


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode46 {
    public static void permute(int[] numbers, List<List<Integer>> allsets, List<Integer> currset, boolean[] used){
        if(currset.size()==numbers.length){
            allsets.add(new ArrayList<>(currset));
        }
        for(int i=0;i<numbers.length;i++){
            if(used[i]==true){
                continue;
            }
            currset.add(numbers[i]);
            used[i] = true;
            permute(numbers, allsets, currset, used);
            currset.remove(currset.size()-1);
            used[i] = false;
        }
    }
    public static List<List<Integer>> get_permutations(int[] numbers){
        List<List<Integer>> allsets = new ArrayList<>();
        List<Integer> currset = new ArrayList<>();
        boolean[] used = new boolean[numbers.length];
        Arrays.fill(used, false);
        permute(numbers, allsets, currset, used);
        return allsets;
    }
    public static void main(String[] args) {
        int[] numbers = {1, 2, 3};
        List<List<Integer>> permutations = get_permutations(numbers);
        System.out.println(permutations);
    }
}
