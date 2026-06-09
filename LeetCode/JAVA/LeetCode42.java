public class LeetCode42 {
    public static int findWaterTrapped(int[] arr){
        int n = arr.length;
        int leftMax = 0, rightMax = 0, total = 0;
        int left = 0, right = n-1;
        while (left<right) {
            if(arr[left]<=arr[right]){
                if(arr[left]<leftMax){
                    total+=leftMax-arr[left];
                }else{
                    leftMax = arr[left];
                }
                left++;
            }
            else{
                if(arr[right]<rightMax){
                    total+=rightMax-arr[right];
                }
                else{
                    rightMax = arr[right];
                }
                right--;
            }
        }
        return total;
    }
    public static void main(String[] args) {
        int[] arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        int trappedWater = findWaterTrapped(arr);
        System.out.println("The Total Water Trapped In Rainwater Is : " + trappedWater + " Units.");
    }
}
