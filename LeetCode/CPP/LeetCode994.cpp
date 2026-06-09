// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Look For Reference In the Book-2 On Pg No 56-57


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>

using namespace std;

int rotten_oranges(vector<vector<int>>& grid){
    queue<pair<pair<int, int>, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i, j}, ans});
            }
        }
    }
    while(!q.empty()){
        pair polled = q.front();
        q.pop();
        int i = polled.first.first;
        int j = polled.first.second;
        int time = polled.second;
        if(i-1>=0 && grid[i-1][j]==1){
            q.push({{i-1, j}, time+1});
            grid[i-1][j] = 2;
            ans = max(ans, time+1);
        }
        if(j-1>=0 && grid[i][j-1]==1){
            q.push({{i, j-1}, time+1});
            grid[i][j-1] = 2;
            ans = max(ans, time+1);
        }
        if(i+1<n && grid[i+1][j]==1){
            q.push({{i+1, j}, time+1});
            grid[i+1][j] = 2;
            ans = max(ans, time+1);
        }
        if(j+1<m && grid[i][j+1]==1){
            q.push({{i, j+1}, time+1});
            grid[i][j+1] = 2;
            ans = max(ans, time+1);
        }
    }
    for(vector<int> nums : grid){
        for(int num : nums){
            if(num==1){
                return -1;
            }
        }
    }
    return ans;
};

int main(){
    vector<vector<int>> grid = {{2, 1, 1},
                                {1, 1, 0},
                                {0, 1, 1}};
    cout<<"Time To Get All Oranges Rott Is : "<<rotten_oranges(grid);
    return 0;
}