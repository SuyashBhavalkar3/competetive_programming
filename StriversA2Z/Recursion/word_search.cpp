#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dfs_helper(int r, int c, int n, int m, string& target,
                vector<vector<string>>& board, vector<vector<bool>>& visited,
                int wordIndex){
    if(wordIndex == target.size()){
        return true;
    }
    if(r<0 || r>=n || c<0 || c>=m ){
        return false;
    }
    if(visited[r][c] == true || board[r][c][0]!=target[wordIndex]){
        return false;
    }
    visited[r][c] = true;
    bool left = dfs_helper(r, c-1, n, m, target, board, visited, wordIndex+1);
    bool right = dfs_helper(r, c+1, n, m, target, board, visited, wordIndex+1);
    bool top = dfs_helper(r-1, c, n, m, target, board, visited, wordIndex+1);
    bool bottom = dfs_helper(r+1, c, n, m, target, board, visited, wordIndex+1);
    if(left || right || top || bottom){
        return true;
    }
    visited[r][c] = false;
    return false;
}

bool Word_Search(vector<vector<string>>& board, string& target){
    if(board.empty() || board[0].empty() || target.empty()){
        return false;
    }
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j][0] == target[0]){
                if(dfs_helper(i, j, n, m, target, board, visited, 0)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    vector<vector<string>> board = {{"A", "B", "C", "E"},
                                    {"S", "F", "C", "S"},
                                    {"A", "D", "E", "E"}};
    string target = "ABCCED";
    bool wordFound = Word_Search(board, target);
    cout<<"The Word Found In Board : "<<boolalpha<<wordFound<<endl;
    return 0;
}