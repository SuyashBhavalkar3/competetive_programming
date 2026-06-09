// You are given an integer array height of length n.
// There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Look For Reference In the Book On Pg No 142


public class LeetCode11{
    public static int max_water(int[] height){
        int lb = 0;
        int rb = height.length-1;
        int answer = 0;
        while(lb<rb){
            answer = Math.max(answer, (rb-lb)*Math.min(height[rb], height[lb]));
            if(height[lb]<height[rb])   lb++;
            else    rb--;
        }
        return answer;
    }
    public static void main(String[] args) {
        int[] height = {1,8,6,2,5,4,8,3,7};
        System.out.println("Container With Most Filled Water Is : " + max_water(height));
    }
}