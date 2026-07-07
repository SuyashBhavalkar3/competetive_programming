import java.util.Arrays;

public class alloate_minimum_pages{
    public static int ifPages(int[] nums, int m, int mid){
        int n = 1;
        int pages = 0;
        for(int num : nums){
            pages+=num;
            if(pages>mid){
                n++;
                pages = num;
            }
        }
        return n;
    }
    public static int minimum_page(int[] nums, int m){
        int low = Arrays.stream(nums).max().getAsInt();
        int high = Arrays.stream(nums).sum();
        while(low<=high){
            int mid = low + (high - low)/2;
            if(ifPages(nums, m, mid)>m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    public static void main(String[] args) {
        int[] nums = {12, 34, 67, 90};
        int m = 2;
        int minPages = minimum_page(nums, m);
        System.out.println("The minimum page need to allocate is " + minPages);
    }
}