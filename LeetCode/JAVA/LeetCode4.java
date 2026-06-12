// Given two sorted arrays nums1 and nums2 of size m and n respectively,
// return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Look For Reference In the Book-2 On Pg No 5


public class LeetCode4{
    public static double findMedianOfTwoSortedArray(int[] arr1, int[] arr2){
        if(arr1.length>arr2.length){
            return findMedianOfTwoSortedArray(arr2, arr1);
        }
        int n1 = arr1.length;
        int n2 = arr2.length;
        int low = 0;
        int high = n1;
        while(low<=high){
            int cut1 = low + (high-low)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            int left1, left2, right1, right2;
            if(cut1==0)
                left1=Integer.MIN_VALUE;
            else
                left1=arr1[cut1-1];
            if(cut2==0)
                left2=Integer.MIN_VALUE;
            else
                left2=arr2[cut2-1];
            if(cut1==n1)
                right1=Integer.MAX_VALUE;
            else
                right1=arr1[cut1];
            if(cut2==n2)
                right2=Integer.MAX_VALUE;
            else
                right2=arr2[cut2];
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2==0){
                    return (Math.max(left1, left2)+Math.min(right1, right2))/2.0;
                }
                else{
                    return Math.max(left1, left2);
                }
            }
            if(left1>right2)
                high = cut1-1;
            else
                low = cut1+1;
        }
        return 0.0;
    }
    public static void main(String[] args) {
        int[] arr1 = {1, 3, 8, 9};
        int[] arr2 = {7, 11, 18, 19, 21};
        double result = findMedianOfTwoSortedArray(arr1, arr2);
        System.out.println("The Mediam Of Two Sorted Array Is : " + result);
    }
}