// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color.
// Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// Look For Reference In the Book On Pg No 130-131



public class LeetCode733{
    public static void dfs(int sr, int sc, int color, int[][] image, int ogcol){
        if(sr>=image.length||sc>=image.length||sr<0||sc<0)    return;
        if(image[sr][sc]!=ogcol||image[sr][sc]==color)  return;
        image[sr][sc] = color;
        dfs(sr-1, sc, color, image, ogcol);
        dfs(sr+1, sc, color, image, ogcol);
        dfs(sr, sc-1, color, image, ogcol);
        dfs(sr, sc+1, color, image, ogcol);
    }
    public static int[][] floodFill(int[][] image, int sr, int sc, int color){
        int originalColor= image[sr][sc];
        if(originalColor!=color){
            dfs(sr, sc, color, image, originalColor);
        }
        return image;
    }
    public static void main(String[] args){
        int[][] image= {{1,1,0},
                        {1,1,0},
                        {1,0,1}};
        for(int[] row : floodFill(image, 1, 1, 2)){
            for(int element : row){
                System.out.print(element+" ");
            }
            System.out.println();
        }
    }
}