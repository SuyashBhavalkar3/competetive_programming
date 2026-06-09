// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Look For Reference In the Book On Pg No 117



#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices){
    int minPrice = INT_MAX;
    int maxProft = 0;
    for(int price : prices){
        if(price<minPrice)  minPrice = price;
        else if((price - minPrice) > maxProft)  maxProft = price-minPrice;
    }
    return maxProft;
};
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout<<"Maximum Profit Can Be Obtained Is : "<<maxProfit(prices)<<endl;
    return 0;
};