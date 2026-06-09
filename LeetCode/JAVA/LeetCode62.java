// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
// The robot can only move either down or right at any point in time.

// Given the two integers m and n,
// return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Look For Reference In the Book-2 On Pg No 130-131


class Solution_UniquePaths{
    public int unique_path(int m, int n){
        int[][] dp = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else{
                    int left = 0;
                    int up = 0;
                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j>0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
}
public class LeetCode62 {
    public static void main(String[] args) {
        Solution_UniquePaths solution_unique_paths = new Solution_UniquePaths();
        System.out.println("The Unique Paths Are : " + solution_unique_paths.unique_path(3, 7));
    }
}