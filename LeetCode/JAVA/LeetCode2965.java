// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2].
// Each integer appears exactly once except a which appears twice and b which is missing.
// The task is to find the repeating and missing numbers a and b.
// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.


// Look For Reference In the Book On Pg No 28-29


import java.util.Scanner;

public class LeetCode2965 {

    public static int[] findMissingAndRepeating(int[][] grid){
        int n = grid.length;
        int high = n*n;
        int[] temp = new int[2];
        int[] count = new int[high+1];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                count[grid[i][j]]++;
            }
        }
        for(int k=1;k<=high;k++){
            if(count[k] == 0)   temp[0] = k;
            if(count[k]>1)  temp[1] = k;
        }

        return temp;
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter Number Of Rows And Columns In Matrix");
            int n = sc.nextInt();
            int[][] grid = new int[n][n];
            for(int i=0;i<n;i++)
            {
                System.out.println("Enter Elements Of Row "+(i+1));
                for(int j=0;j<n;j++){
                    grid[i][j] = sc.nextInt();
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++){
                    System.out.print(grid[i][j]+" ");
                }
                System.out.println();
            }

            int[] res = findMissingAndRepeating(grid);
                System.out.println("Missing Number Is "+res[0]+" And Repeating Number Is "+res[1]);
        }
    }
}
