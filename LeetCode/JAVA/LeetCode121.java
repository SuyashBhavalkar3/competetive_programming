// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Look For Reference In the Book On Pg No 117


public class LeetCode121 {
    public static int maxProfit(int[] prices){
        int maxprofitis = 0;
        int min_price = Integer.MAX_VALUE;
        for(int price : prices){
            if(price<min_price){
                min_price = price;
            }
            else if(price - min_price > maxprofitis){
                maxprofitis = price - min_price;
            }
        }
        return maxprofitis;
    }
    public static void main(String[] args) {
        int[] prices = {7,1,5,3,6,4};
        System.out.println("Maximum Profit Can Be Obtained Is : " + maxProfit(prices));
    }
}
