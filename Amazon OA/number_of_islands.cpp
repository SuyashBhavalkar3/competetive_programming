#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, int j , int n, int m, vector<vector<bool>>& visited, vector<vector<char>>& grid){
    if(i<0 ||j<0 ||i>=n || j>=m || visited[i][j] == true || grid[i][j] == '0'){
        return;
    }
    visited[i][j] = true;
    dfs(i+1, j, n, m, visited, grid);
    dfs(i-1, j, n, m, visited, grid);
    dfs(i, j-1, n, m, visited, grid);
    dfs(i, j+1, n, m, visited, grid);
    return;
}

int Number_Of_Island(vector<vector<char>>& grid){
    int Islands = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '1' && visited[i][j] == false){
                Islands++;
                dfs(i, j, n, m, visited, grid);
            }
        }
    }
    return Islands;
}

int main(){
    vector<vector<char>> grid = {
                                {'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','1'}
                               };
    int numIslands = Number_Of_Island(grid);
    cout<<"The Number Of Islands Are : "<<numIslands<<endl;
    return 0;
}