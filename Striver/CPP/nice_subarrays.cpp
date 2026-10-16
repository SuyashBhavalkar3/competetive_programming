#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int> &nums, int k) {
  int n = nums.size();
  if (n < k) {
    return 0;
  }
  int count = 0;
  int left = 0;
  int odd = 0;
  int right = 0;
  while (right < n) {
    if (nums[right] % 2 == 1) {
      odd++;
    }
    while (odd > k) {
      if (nums[left] % 2 == 1) {
        odd--;
      }
      left++;
    }
    count += right - left + 1;
    right++;
  }
  return count;
}

int numberOfSubarrays(vector<int> &nums, int k) {
  int a = helper(nums, k);
  int b = helper(nums, k - 1);
  return a - b;
}

int main() {
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  int res = numberOfSubarrays(nums, k);
  cout << "The Number Of Nice SubArrays Are : " << res << endl;
  return 0;
}