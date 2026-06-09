// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Look For Reference In the Book-2 On Pg No 98-99


import java.util.ArrayList;
import java.util.List;

public class LeetCode118 {
    public static List<Integer> helper(int n){
        List<Integer> ansList = new ArrayList<>();
        ansList.add(1);
        int ans = 1;
        for(int i=1;i<n;i++){
            ans = ans*(n-i);
            ans = ans/i;
            ansList.add(ans);
        }
        return ansList;
    }
    public static List<List<Integer>> pascalTraingle(int numRows){
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=1;i<=numRows;i++){
            ans.add(helper(i));
        }
        return ans;
    }
    public static void main(String[] args) {
        int numRows = 6;
        System.out.println(pascalTraingle(numRows));
    }
}