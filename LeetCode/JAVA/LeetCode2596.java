// There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every cell on the board exactly once.

// You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] indicates that the cell (row, col) is the
// grid[row][col]th cell that the knight visited. The moves are 0-indexed.

// Return true if grid represents a valid configuration of the knight's movements or false otherwise.

// Note that a valid knight move consists of moving two squares vertically and one square horizontally, or two squares horizontally and one square vertically.
// The figure below illustrates all the possible eight moves of a knight from some cell.

// Look For Reference In the Book-2 On Pg No 48-49


public class LeetCode2596 {
    public static boolean helper(int[][] grid, int r, int c, int n, int expVal){
        if(r<0||c<0||r>n-1||c>n-1||grid[r][c]!=expVal){
            return false;
        }
        if(expVal==n*n-1){
            return true;
        }
        expVal++;
        boolean ans1 = helper(grid, r-2, c-1, n, expVal);
        boolean ans2 = helper(grid, r-2, c+1, n, expVal);
        boolean ans3 = helper(grid, r-1, c-2, n, expVal);
        boolean ans4 = helper(grid, r-1, c+2, n, expVal);
        boolean ans5 = helper(grid, r+1, c-2, n, expVal);
        boolean ans6 = helper(grid, r+1, c+2, n, expVal);
        boolean ans7 = helper(grid, r+2, c-1, n, expVal);
        boolean ans8 = helper(grid, r+2, c+1, n, expVal);
        return (ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8);
    }
    public static boolean checkValidGrid(int[][] grid){
        return helper(grid, 0, 0, grid.length, 0);
    }
    public static void main(String[] args) {
        int[][] grid = {{0, 11, 16, 5, 20},
                        {17, 4, 19, 10, 15},
                        {12, 1, 8, 21, 6},
                        {3, 18, 23, 14, 9},
                        {24, 13, 2, 7, 22}};

        System.out.println("The Knight Tour Is Possible : " + checkValidGrid(grid));
    }
}