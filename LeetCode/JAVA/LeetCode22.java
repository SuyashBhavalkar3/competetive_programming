// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Look For Reference In the Book-2 On Pg No 91-92


import java.util.ArrayList;
import java.util.List;

public class LeetCode22{
    public static void solve(List<String> ans, String currString, int open, int close, int total){
        if(currString.length()==2*total){
            ans.add(currString);
            return;
        }
        if(open<total){
            solve(ans, currString+"(", open+1, close, total);
        }
        if(close<open){
            solve(ans, currString+")", open, close+1, total);
        }
    }
    public static List<String> valid_parenthesis(int n){
        List<String> ans = new ArrayList<>();
        solve(ans, "", 0, 0, n);
        return ans;
    }
    public static void main(String[] args) {
        int n = 3;
        List<String> result = valid_parenthesis(n);
        System.out.println(result);
    }
}