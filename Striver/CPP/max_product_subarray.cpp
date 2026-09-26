#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int maximum_product_subarray(vector<int> &nums) {
  int n = nums.size();
  int suffix = 1;
  int prefix = 1;
  int maxInt = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (prefix == 0) {
      prefix = 1;
    }
    if (suffix == 0) {
      suffix = 1;
    }
    prefix *= nums[i];
    suffix *= nums[n - 1 - i];
    maxInt = max(maxInt, max(suffix, prefix));
  }
  return maxInt;
}

int main() {
  vector<int> nums = {2, 3, -2, 4};
  int result = maximum_product_subarray(nums);
  cout << "Maximum product subarray is : " << result << endl;
  return 0;
}