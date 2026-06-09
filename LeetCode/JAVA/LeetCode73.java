// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Look For Reference In the Book-2 On Pg No 96-97


class LeetCode73{
    public static void setMatrixZero(int[][] matrix){
        boolean firstColZero = false;
        for(int[] matrix1 : matrix) {
            if (matrix1[0] == 0) {
                firstColZero=true;
            }
            for (int j = 1; j<matrix[0].length; j++) {
                if (matrix1[j] == 0) {
                    matrix1[0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<matrix.length;i++){
            for(int j=1;j<matrix[0].length;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<matrix[0].length;i++){
                matrix[0][i] = 0;
            }
        }
        if(firstColZero){
            for(int[] matrix1 : matrix) {
                matrix1[0] = 0;
            }
        }
    }
    public static void main(String[] args){
        int[][] matrix = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
        };
        setMatrixZero(matrix);
        for(int[] arr : matrix){
            for(int num : arr){
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}