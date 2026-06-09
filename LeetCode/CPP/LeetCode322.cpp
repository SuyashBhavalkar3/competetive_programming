// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Look For Reference In the Book-2 On Pg No 69


#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int coin_change(vector<int>& coins, int amount){
    vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, INT_MAX-1));
    int n = coins.size();
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(j<coins[i-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
            }
        }
    }
    if(dp[n][amount] == INT_MAX-1){
        return -1;
    }
    return dp[n][amount];
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout<<coin_change(coins, amount)<<endl;
    return 0;
}