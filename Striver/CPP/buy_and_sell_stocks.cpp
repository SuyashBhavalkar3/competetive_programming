#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int buy_and_sell_stocks(vector<int> prices) {
  int maxProfit = 0;
  int minPrice = INT_MAX;
  for (int price : prices) {
    if (price < minPrice) {
      minPrice = price;
    } else {
      maxProfit = max(maxProfit, price - minPrice);
    }
  }
  return maxProfit;
}

int main() {
  vector<int> stocks = {7, 1, 5, 3, 6, 4};
  int maxProfit = buy_and_sell_stocks(stocks);
  cout << maxProfit << endl;
  return 0;
}