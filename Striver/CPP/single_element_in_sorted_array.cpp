#include <iostream>
#include <vector>

using namespace std;

int single_element(vector<int> &nums) {
  int n = nums.size();
  if (n == 1) {
    return nums[0];
  }
  if (nums[0] != nums[1]) {
    return nums[0];
  }
  if (nums[n - 1] != nums[n - 2]) {
    return nums[n - 1];
  }
  int low = 1;
  int high = n - 2;
  while (low <= high) {
    int pivot = low + (high - low) / 2;
    if (nums[pivot] != nums[pivot - 1] && nums[pivot] != nums[pivot + 1]) {
      return nums[pivot];
    }
    if ((pivot % 2 == 1 && nums[pivot] == nums[pivot - 1]) ||
        (pivot % 2 == 0 && nums[pivot] == nums[pivot + 1])) {
      low = pivot + 1;
    } else {
      high = pivot - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  int singleElement = single_element(nums);
  cout << "The Single Element In Array Is : " << singleElement << endl;
  return 0;
}