// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Look For Reference In the Book-2 On Pg No 56-57


import java.util.LinkedList;
import java.util.Queue;

public class LeetCode994{
    public static class Pair{
        int first, second, time;
        Pair(int f, int s, int t){
            this.first = f;
            this.second = s;
            this.time = t;
        }
    }
    public static int rotten_orange(int[][] grid){
        int n = grid.length;
        int m = grid[0].length;
        int ans = 0;         //initial time
        Queue<Pair> q = new LinkedList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.add(new Pair(i, j, ans));
                }
            }
        }
        while(!q.isEmpty()){
            Pair polled = q.poll();
            int i = polled.first;
            int j = polled.second;
            int time = polled.time;
            if(i-1>=0 && grid[i-1][j]==1){
                q.add(new Pair(i-1, j, time+1));
                grid[i-1][j] = 2;
                ans = Math.max(ans, time+1);
            }
            if(i+1<=n-1 && grid[i+1][j]==1){
                q.add(new Pair(i+1, j, time+1));
                grid[i+1][j] = 2;
                ans = Math.max(ans, time+1);
            }
            if(j-1>=0  && grid[i][j-1]==1){
                q.add(new Pair(i, j-1, time+1));
                grid[i][j-1] = 2;
                ans = Math.max(ans, time+1);
            }
            if(j+1<=m-1 && grid[i][j+1]==1){
                q.add(new Pair(i, j+1, time+1));
                grid[i][j+1] = 2;
                ans = Math.max(ans, time+1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return  ans;
    }
    public static void main(String[] args) {
        int[][] grid = {{2, 1, 1},
                        {1, 1, 1},
                        {1, 0, 1}};
        System.out.println(rotten_orange(grid));
    }
}