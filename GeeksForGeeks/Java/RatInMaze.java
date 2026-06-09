// Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.

// Note: Return the final result vector in lexicographically smallest order.


// Look For Reference In the Book-2 On Pg No 54-55

import java.util.ArrayList;
import java.util.List;

public class RatInMaze{
    public static void solve(int i, int j, List<String> ans, String path, int n,
                             int m, boolean[][] visited, int[][] maze){
        if(i==n-1 && j==m-1){
            ans.add(new String(path));
            return;
        }
        if(i+1<n && visited[i+1][j]==false && maze[i+1][j]==1){
            visited[i+1][j] = true;
            solve(i+1, j, ans, path + 'D', n, m, visited, maze);
            visited[i+1][j] = false;
        }
        if(i-1>=0 && visited[i-1][j]==false && maze[i-1][j]==1){
            visited[i-1][j] = true;
            solve(i-1, j, ans, path + 'U', n, m, visited, maze);
            visited[i-1][j] = false;
        }
        if(j+1<m && visited[i][j+1]==false && maze[i][j+1]==1){
            visited[i][j+1] = true;
            solve(i, j+1, ans, path + 'R', n, m, visited, maze);
            visited[i][j+1] = false;
        }
        if(j-1>=0 && visited[i][j-1]==false && maze[i][j-1]==1){
            visited[i][j-1] = true;
            solve(i, j-1, ans, path + 'L', n, m, visited, maze);
            visited[i][j-1] = false;
        }
    }
    public static List<String> getAns(int [][] maze){
        List<String> ans = new ArrayList<>();
        boolean[][] visited = new boolean[maze.length][maze[0].length];
        if(maze[0][0]==1){
            visited[0][0] = true;
            solve(0, 0, ans, "", maze.length, maze[0].length, visited, maze);
        }
        return ans;
    }
    public static void main(String[] args) {
        int[][] maze = {{1, 0, 0, 0},
                        {1, 1, 0, 1},
                        {1, 1, 0, 0},
                        {0, 1, 1, 1}};
        List<String> paths = getAns(maze);
        for(String path : paths){
            System.out.println(path);
        }
    }
}