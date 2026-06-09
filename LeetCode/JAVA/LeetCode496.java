// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
// If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Look For Reference In the Book On Pg No 38-39-40


import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

public class LeetCode496 {
    
    public static int[] nextGreaterElement(int[] nums1, int[] nums2){
        HashMap<Integer, Integer> map = new HashMap<>();
        Stack<Integer> monotonicSt = new Stack<>();

        int n2 = nums2.length;
        for(int i=0;i<n2;i++){
            while(!monotonicSt.isEmpty()&&nums2[i]>monotonicSt.peek()){
                    map.put(monotonicSt.pop(), nums2[i]);
            }
            monotonicSt.push(nums2[i]);
        }
        while(!monotonicSt.isEmpty()){
            map.put(monotonicSt.pop(), -1);
        }

        int[] ans = new int[nums1.length];
        for(int i=0;i<ans.length;i++){
            ans[i] = map.get(nums1[i]);
        }

        return ans;
    }

    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter Limit Of Array 1 : ");
            int limit1 = sc.nextInt();
            int[] nums1 = new int[limit1];
            System.out.println("Enter Elements Of Array 1 : ");
            for(int i=0;i<limit1;i++){
                nums1[i] = sc.nextInt();
            }
            System.out.println("Enter Limit Of Array 2 : ");
            int limit2 = sc.nextInt();
            int[] nums2 = new int[limit2];
            System.out.println("Enter Elements Of Array 2");
            for(int i=0;i<limit2;i++){
                nums2[i] = sc.nextInt();
            }
            int res[] = nextGreaterElement(nums1, nums2);
            System.out.print("[");
            for(int i=0;i<res.length;i++){
                System.out.print(res[i]);
                if(i!=res.length-1)
                System.out.print(", ");
            }
            System.out.print("]");
        }
    }

}
