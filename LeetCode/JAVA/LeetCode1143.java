// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Look For Reference In the Book-2 On Pg No 80-81


public class LeetCode1143 {
    public static int longestCommonSubsequence(char[] text1, char[] text2){
        int n = text1.length;
        int m = text2.length;
        int[][] dp = new int[n+1][m+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    public static void main(String[] args){
        String text1 = "abcde";
        String text2 = "ace";
        System.out.println("Longest Common Subsequence Is : " + longestCommonSubsequence(text1.toCharArray(), text2.toCharArray()));
    }
}
