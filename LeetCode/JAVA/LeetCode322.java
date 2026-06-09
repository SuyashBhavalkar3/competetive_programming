// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Look For Reference In the Book-2 On Pg No 69



import java.util.Arrays;

public class LeetCode322 {
    public static int coin_change(int[] coins, int amount){
        int n = coins.length;
        int[][] dp = new int[n+1][amount+1];
        for(int[] arr : dp){
            Arrays.fill(arr, Integer.MAX_VALUE-1);
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j<coins[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = Math.min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
                }
            }
        }
        if(dp[n][amount]==Integer.MAX_VALUE-1){
            return -1;
        }
        return dp[n][amount];
    }
    public static void main(String[] args) {
        int[] coins = {1,2,5};
        int amount = 11;
        int result = coin_change(coins, amount);
        System.out.println(result);
    }
}