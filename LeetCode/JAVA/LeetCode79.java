// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once.

// Look For Reference In the Book-2 On Pg No 94-95


public class LeetCode79 {
    
    public static boolean dfs(char [][] board, char[] wordChar, int idx, int n, int i, int j){
        if(i<0||j<0||i>=board.length||j>=board[0].length||board[i][j]!=wordChar[idx]){
            return false;
        }
        if(idx==n-1){
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        boolean found = dfs(board, wordChar, idx+1, n, i+1, j) ||
                        dfs(board, wordChar, idx+1, n, i-1, j) ||
                        dfs(board, wordChar, idx+1, n, i, j+1) ||
                        dfs(board, wordChar, idx+1, n, i, j-1);
        board[i][j] = temp;
        return found;
    }
    public static boolean exists(char[][] board, String word){
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(dfs(board, word.toCharArray(), 0, word.length(), i, j)){
                    return true;
                }
            }
        }
        return false;
    }
    public static void main(String[] args) {
        char[][] board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };
        String word = "ABCCED";
        boolean result = exists(board, word);
        System.out.println("The word \"" + word + "\" exists in the board: " + result);
    }
}
