// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

// Look For Reference In the Book-2 On Pg No 101


public class LeetCode48{
    public static void reverseRow(int[] matrix){
        int a = 0;
        int b = matrix.length-1;
        while(a<b){
            int temp = matrix[a];
            matrix[a] = matrix[b];
            matrix[b] = temp;
            a++;
            b--;
        }
    }
    public static void rotationOfMatrix(int[][] matrix){
        for(int i=0;i<matrix.length;i++){
            for(int j=i+1;j<matrix[0].length;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int[] row : matrix){
            reverseRow(row);
        }
    }
    public static void main(String[] args) {
        int[][] matrix = {
                {1,2,3},
                {4,5,6},
                {7,8,9}};
        System.out.println("Original Matrix : ");
        for(int[] row : matrix){
            for(int num:row){
                System.out.print(num+" ");
            }
            System.out.println();
        }
        rotationOfMatrix(matrix);
        System.out.println("Rotated Matrix : ");
        for(int[] row: matrix){
            for(int num : row){
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}