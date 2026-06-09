// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Look For Reference In the Book-2 On Pg No 78-79


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LeetCode300{
    public static int LIS(int[] arr){
        List<Integer> temp = new ArrayList<>();
        temp.add(arr[0]);
        int len = 1;
        for(int i=1;i<arr.length;i++){
            if(temp.get(temp.size()-1)<arr[i]){
                temp.add(arr[i]);
                len++;
            }
            else{
                int idx = Collections.binarySearch(temp, arr[i]);
                if(idx<0){
                    idx = -(idx+1);
                }
                temp.set(idx, arr[i]);
            }
        }
        return len;
    }
    public static void main(String[] args){
        int[] arr = {10,9,2,5,3,7,101,18};
        System.out.println("Length of Longest Increasing Subsequence is : "+LIS(arr));
    }
}