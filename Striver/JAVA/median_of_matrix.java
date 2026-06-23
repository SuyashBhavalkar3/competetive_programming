public class median_of_matrix{
    public static int upperBound(int[] row, int mid){
        int cnt = 0;
        for(int i=0;i<row.length;i++){
            if(row[i]>mid){
                return cnt;
            }
            cnt++;
        }
        return cnt;
    }
    public static int countSmallersThanMid(int mid, int[][] arr){
        int cnt = 0;
        for(int i=0;i<arr.length;i++){
            cnt+=upperBound(arr[i], mid);
        }
        return cnt;
    }
    public static int findMedianOfMatrix(int[][] arr){
        int n = arr.length;
        int m = arr[0].length;
        int req = (n*m)/2;
        int low = Integer.MAX_VALUE;
        int high = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            low = Math.min(low, arr[i][0]);
            high = Math.max(high, arr[i][m-1]);
        }
        while(low<=high){
            int mid = low + ((high - low)/2);
            int smaller = countSmallersThanMid(mid, arr);
            if(smaller<=req){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    public static void main(String[] args) {
        int[][] arr = {{1, 5, 7, 9, 11},
                       {2, 3, 4, 5, 10},
                       {9, 10, 12, 14, 16}};
        int median = findMedianOfMatrix(arr);
        System.out.println("The Median Of Matris Is : "  +  median);
    }
}