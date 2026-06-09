// Count Inversions

// Given an integer array nums. Return the number of inversions in the array.

// Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// It indicates how close an array is to being sorted.

// A sorted array has an inversion count of 0.

// An array sorted in descending order has maximum inversion.

// Look For Reference In the Book-2 On Pg No 108-109


public class count_inversions{
    public static int inversions(int[] arr, int low, int pivot, int high){
        int cnt = 0;
        int l1 = pivot - low + 1;
        int r1 = high - pivot;
        int[] L = new int[l1];
        int[] R = new int[r1];
        for(int i=0;i<l1;i++){
            L[i] = arr[low + i];
        }
        for(int i=0;i<r1;i++){
            R[i] = arr[pivot + i + 1];
        }
        int i = 0, j = 0, k = low;
        while(i<l1 && j<r1){
            if(L[i]<=R[j]){
                arr[k++] = L[i++];
            }
            else{
                arr[k++] = R[j++];
                cnt+=l1-i;
            }
        }
        while(i<l1){
            arr[k++] = L[i++];
        }
        while(j<r1){
            arr[k++] = R[j++];
        }
        return cnt;
    }
    public static int countInversion(int[] arr, int low, int high){
        int count = 0;
        if(low>=high)   return count;
        int pivot = low + (high - low)/2;
        count+=countInversion(arr, low, pivot);
        count+=countInversion(arr, pivot+1, high);
        count+=inversions(arr, low, pivot, high);
        return count;
    }
    public static void main(String[] args) {
        int[] arr = {1, 20, 6, 4, 5};
        System.out.println("The number of inversions in the array is: "+countInversion(arr, 0, arr.length-1));
    }
}