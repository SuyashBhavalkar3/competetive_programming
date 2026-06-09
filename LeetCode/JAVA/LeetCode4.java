// Given two sorted arrays nums1 and nums2 of size m and n respectively,
// return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Look For Reference In the Book-2 On Pg No 5


public class LeetCode4{
    public static double getMedian(int[] nums1, int[] nums2){
        if(nums1.length>nums2.length){
            return getMedian(nums2, nums1);
        }
        int X = nums1.length;
        int Y = nums2.length;
        int low = 0;
        int high = X;
        while(low<=high){
            int partitionX = low + (high-low)/2;
            int partitionY = (X + Y + 1)/2 - partitionX;
            int maxLeftX = (partitionX==0)? Integer.MIN_VALUE : nums1[partitionX-1];
            int maxLeftY = (partitionY==0)? Integer.MIN_VALUE : nums2[partitionY-1];
            int minRightX = (partitionX==X)? Integer.MAX_VALUE : nums1[partitionX];
            int minRightY = (partitionY==Y)? Integer.MAX_VALUE : nums2[partitionY];
            if((maxLeftX<=minRightY) && (maxLeftY<=minRightX)){
                if((X+Y)%2==0){
                    return (double)((Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY))/2);
                }
                else{
                    return (double)(Math.max(maxLeftX, maxLeftY));
                }
            }
            else if(maxLeftX>minRightY){
                high = partitionX-1;
            }
            else{
                low = partitionX+1;
            }
        }
        return 0.0;
    }
    public static void main(String[] args){
        int[] arr1 = {1, 3, 8, 9};
        int[] arr2 = {7, 11, 18, 19, 21};
        double median = getMedian(arr1, arr2);
        System.out.println("Median Of Two Sorted Arrays Are : " + median);
    }
}