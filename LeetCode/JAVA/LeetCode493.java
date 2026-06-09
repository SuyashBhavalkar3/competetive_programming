// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

// Look For Reference In the Book-2 On Pg No 128-129


public class LeetCode493 {
    public static int merge_arr(int[] arr, int low, int mid, int high){
        int cnt = 0;
        int j = mid + 1;
        for(int i=low;i<=mid;i++){
            while(j<=high  && (long)arr[i]>(long)2*arr[j]){
                j++;
            }
            cnt+= j-(mid+1);
        }
        int l1 = mid - low + 1;
        int r1 = high - mid;
        int[] L = new int[l1];
        int[] R = new int[r1];
        for(int i = 0; i<l1; i++){
            L[i] = arr[low + i];
        }
        for(int i = 0; i<r1;i++){
            R[i] = arr[mid + i + 1];
        }
        int left = 0, right = 0, k = low;
        while(left<l1 && right<r1){
            if(L[left]<=R[right]){
                arr[k++] = L[left++];
            }
            else{
                arr[k++] = R[right++];
            }
        }
        while(left<l1){
            arr[k++] = L[left++];
        }
        while (right<r1) {
            arr[k++] = R[right++];
        }
        return cnt;
    }
    public static int merge_sort(int[] arr, int low, int high){
        int cnt = 0;
        if(low>=high)    return cnt;
        int mid = low + (high - low)/2;
        cnt+=merge_sort(arr, low, mid);
        cnt+=merge_sort(arr, mid+1, high);
        cnt+=merge_arr(arr, low, mid, high);
        return cnt;
    }
    public static void main(String[] args) {
        int[] arr = {1, 3, 2, 3, 1};
        System.out.println("Number Pairs To Reserve Are : " + merge_sort(arr, 0, arr.length-1));
    }
}