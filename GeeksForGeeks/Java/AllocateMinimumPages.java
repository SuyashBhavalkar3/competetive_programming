// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students.
// The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student.
// In other words, out of all possible allocations,
// find the arrangement where the student who receives the most pages still has the smallest possible maximum.


// Look For Reference In the Book On Pg No 92-93


import java.util.Arrays;

public class AllocateMinimumPages {
    public static boolean isPossible(int n, int[] arr, int k, int mid){
        int studCount = 1;
        int pages = 0;
        for(int pagesCnt : arr){
            if(pagesCnt>mid){
                return false;
            }
            if(pages+pagesCnt>mid){
                studCount++;
                pages = pagesCnt;
                if(studCount>k){
                    return false;
                }
            }
            else{
                pages+=pagesCnt;
            }
        }
        return true;
    }
    public static int allocateMin(int[] arr, int k){
        int result = -1;
        int low = Arrays.stream(arr).max().getAsInt();
        int high = Arrays.stream(arr).sum();
        if(arr.length<k)    return -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(arr.length, arr, k, mid)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
    public static void main(String[] args) {
        int[] arr = {12, 34, 67, 90};
        int k = 2;
        System.out.println("Minimum Posiible Maximum Pages Are : " + allocateMin(arr, k));
    }
}
