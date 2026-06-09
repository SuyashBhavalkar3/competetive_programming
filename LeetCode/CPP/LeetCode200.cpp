// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

// Look For Reference In the Book-2 On Pg No 33-34



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int i, int j, vector<vector<char>>& grid){
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!='1'){
        return;
    }
    grid[i][j] = '0';
    dfs(i+1, j, grid);
    dfs(i, j+1, grid);
    dfs(i, j-1, grid);
    dfs(i-1, j, grid);
};

int islands(vector<vector<char>>& grid){
    int cnt=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){
                dfs(i, j, grid);
                cnt++;
            }
        }
    }
    return cnt;
};

int main(){
    vector<vector<char>> grid = {
                                    {'1','1','1','1','0'},
                                    {'1','1','0','1','0'},
                                    {'1','1','0','0','0'},
                                    {'0','0','0','1','0'}
                                };
    cout<<"Count Of No Of Islands Are : "<<islands(grid)<<endl;
    return 0;
}