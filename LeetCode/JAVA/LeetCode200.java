// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

// Look For Reference In the Book-2 On Pg No 33-34



import java.util.Arrays;

public class LeetCode200 {
    public static void dfs(int i, int j, boolean[][] visited, char[][] grid){
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length ||
            grid[i][j] != '1' || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        dfs(i-1, j, visited, grid);
        dfs(i+1, j, visited, grid);
        dfs(i, j-1, visited, grid);
        dfs(i, j+1, visited, grid);
    }
    public static int islands(char[][] grid){
        int n = grid.length;
        int m = grid[0].length;
        int islandCnt = 0;
        boolean[][] visited = new boolean[n][m];
        for(boolean[] arr : visited){
            Arrays.fill(arr, false);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(i, j, visited, grid);
                    islandCnt++;
                }
            }
        }
        return islandCnt;
    }
    public static void main(String[] args){
        char[][] grid = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'1','1','0','1','1'},
            {'0','0','0','1','1'}
            };
        System.out.println("Number Of Islands Are : " + islands(grid));
    }
}
