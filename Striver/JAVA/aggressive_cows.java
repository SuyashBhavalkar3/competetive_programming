import java.util.Arrays;

public class aggressive_cows {
    public static boolean canWePlace(int[] nums, int mid, int k) {
        int cows = 1;
        int last = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] - last >= mid) {
                cows++;
                last = nums[i];
            }
            if (cows >= k) {
                return true;
            }
        }
        return false;
    }

    public static int maxOfMinDist(int[] nums, int k) {
        Arrays.sort(nums);
        int low = 1;
        int high = Arrays.stream(nums).max().getAsInt() - Arrays.stream(nums).min().getAsInt();
        int ans = Integer.MIN_VALUE;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canWePlace(nums, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = { 0, 3, 4, 7, 10, 9 };
        int k = 4;
        int dist = maxOfMinDist(nums, k);
        System.out.println("Maximum Distance Between Minimum Cows : " + dist);
    }
}
