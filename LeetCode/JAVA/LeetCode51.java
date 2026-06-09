// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


// Look For Reference In the Book-3 On Pg No 82-83

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode51 {
    public static void solve(int col, char[][] board, int[] leftRow, int[] upperDiagonal, int[] lowerDiagonal, int n, List<List<String>> allans) {
        if(col==board.length){
            List<String> temp = new ArrayList<>();
            for(int i=0;i<n;i++){
                temp.add(new String(board[i]));
            }
            allans.add(new ArrayList<>(temp));
            return;
        }
        for(int row = 0; row<n; row++){
            if(leftRow[row]==0 && lowerDiagonal[row + col]==0 && upperDiagonal[n-1 + col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row + col]=1;
                upperDiagonal[n-1 + col-row]=1;
                solve(col+1, board, leftRow, upperDiagonal, lowerDiagonal, n, allans);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row + col]=0;
                upperDiagonal[n-1 + col-row]=0;
            }
        }
    }
    public static List<List<String>> solveNQueens(int n){
        List<List<String>> allans = new ArrayList<>();
        char[][] board = new char[n][n];
        for(char[] row : board){
            Arrays.fill(row, '.');
        }
        int[] leftRow = new int[n];
        int[] upperDiagonal = new int[2*n-1];
        int[] lowerDiagonal = new int[2*n-1];
        Arrays.fill(leftRow, 0);
        Arrays.fill(upperDiagonal, 0);
        Arrays.fill(lowerDiagonal, 0);
        solve(0, board, leftRow, upperDiagonal, lowerDiagonal, n, allans);
        return allans;
    }
    public static void main(String[] args) {
        int n = 4;
        List<List<String>> NQueens = solveNQueens(n);
        System.out.println(NQueens); 
    }
}
