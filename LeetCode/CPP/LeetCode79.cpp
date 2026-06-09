// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once.

// Look For Reference In the Book-2 On Pg No 94-95


#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool dfs(vector<vector<char>>& board, string word, int idx, int n, int i, int j){
    if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[idx]){
        return false;
    }
    if(idx==n-1){
        return true;
    }
    char temp = board[i][j];
    board[i][j] = '#';
    bool found = dfs(board, word, idx+1, n, i+1, j)||
                    dfs(board, word, idx+1, n, i-1, j)||
                        dfs(board, word, idx+1, n, i, j+1)||
                            dfs(board, word, idx+1, n, i, j-1);
    board[i][j] = temp;
    return found;
};

bool exists(vector<vector<char>>& board, string word){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(dfs(board, word, 0, word.size(), i, j)){
                return true;
            }
        }
    }
    return false;
};

int main(){
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout<<boolalpha;
    cout<<"The word \""<<word<<"\" exists in the board: "<<exists(board, word)<<endl;
    return 0;
}