// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Look For Reference In the Book-2 On Pg No 19


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode56 {
    public static int[][] mergerIntervals(int[][] matrix){
        Arrays.sort(matrix, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> result = new ArrayList<>();
        result.add(matrix[0]);
        for(int i=1;i<matrix.length;i++){
            if(result.get(result.size()-1)[1]>=matrix[i][0]){
                result.get(result.size()-1)[1] = Math.max(result.get(result.size()-1)[1], matrix[i][1]);
            }
            else{
                result.add(matrix[i]);
            }
        }
        return result.toArray(new int[0][]);
    }
    public static void main(String[] args) {
        int[][] matrix = {
                            {1, 3},
                            {2, 6},
                            {8, 10},
                            {15, 18}
                        };
        int[][] result = mergerIntervals(matrix);
        List<int[]> newList = new ArrayList<>(Arrays.asList(result));
        for(int[] row:newList){
            System.out.println(Arrays.toString(row));
        }
    }
}
