#include <iostream>
#include <vector>

using namespace std;

int peak_element(vector<int> &nums) {
  int n = nums.size();
  if (n == 1) {
    return 0;
  }
  int low = 0;
  int high = n - 1;
  while (low < high) {
    int pivot = low + (high - low) / 2;
    if (nums[pivot] < nums[pivot + 1]) {
      low = pivot + 1;
    } else {
      high = pivot;
    }
  }
  return low;
}

int main() {
  vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
  int peak = peak_element(nums);
  cout << "The peak element is : " << peak << endl;
}