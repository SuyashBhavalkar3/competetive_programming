// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


// Look For Reference In the Book-3 On Pg No 82-83


#include<iostream>
#include<vector>

using namespace std;

void solve(int column, vector<vector<string>>& allboards, vector<string>& board, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int n){
    if(column == n){
        allboards.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && lowerDiagonal[row + column]==0 && upperDiagonal[n-1 + column-row]==0){
            leftRow[row]=1;
            lowerDiagonal[row + column]=1;
            upperDiagonal[n-1 + column-row]=1;
            board[row][column]='Q';
            solve(column+1, allboards, board, leftRow, lowerDiagonal, upperDiagonal, n);
            board[row][column]='.';
            leftRow[row]=0;
            lowerDiagonal[row + column]=0;
            upperDiagonal[n-1 + column-row]=0;
        }
    }
}

vector<vector<string>> get_boards(int n){
    vector<vector<string>> allboards;
    vector<string> board(n, string(n, '.'));
    vector<int> leftRow(n, 0);
    vector<int> lowerDiagonal(2*n-1, 0);
    vector<int> upperDiagonal(2*n-1, 0);
    solve(0, allboards, board, leftRow, lowerDiagonal, upperDiagonal, n);
    return allboards;
}

int main(){
    int n = 4;
    vector<vector<string>> boards = get_boards(n);
    for(vector<string> board : boards){
        for(string row : board){
            cout<<"["<<row<<"]";
            cout<<endl;
        }
        cout<<endl;
    }
}