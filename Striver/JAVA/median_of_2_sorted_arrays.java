public class median_of_2_sorted_arrays {
    public static int findMedianOfTwoSortedArrays(int[] nums1, int[] nums2, int n, int m, int k) {
        if (n > m) {
            return findMedianOfTwoSortedArrays(nums2, nums1, m, n, k);
        }
        int low = Math.max(0, k - m);
        int high = Math.min(k, n);
        int l1, l2, r1, r2;
        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = k - cut1;
            if (cut1 == 0) {
                l1 = Integer.MIN_VALUE;
            } else {
                l1 = nums1[cut1 - 1];
            }
            if (cut1 == n) {
                r1 = Integer.MAX_VALUE;
            } else {
                r1 = nums1[cut1];
            }
            if (cut2 == 0) {
                l2 = Integer.MIN_VALUE;
            } else {
                l2 = nums2[cut2 - 1];
            }
            if (cut2 == m) {
                r2 = Integer.MAX_VALUE;
            } else {
                r2 = nums2[cut2];
            }
            if (l1 <= r2 && l2 <= r1) {
                return Math.max(l1, l2);
            }
            if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] nums1 = { 2, 3, 6, 7, 9 };
        int[] nums2 = { 1, 4, 8, 10 };
        int median = findMedianOfTwoSortedArrays(nums1, nums2, nums1.length, nums2.length, 5);
        if (median != -1) {
            System.out.println("The Median Of Two Sorted Arrays : " + median + ".");
        } else {
            System.out.println("No Median Found.");
        }
    }
}
