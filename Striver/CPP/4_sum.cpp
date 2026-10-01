#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> find_IV_Sum(vector<int> &nums, int target) {
  int n = nums.size();
  if (n < 4) {
    return {{}};
  }
  sort(nums.begin(), nums.end());
  vector<vector<int>> quadlets;
  for (int first = 0; first < n - 3; first++) {
    if (first > 0 && nums[first] == nums[first - 1]) {
      continue;
    }
    for (int second = first + 1; second < n - 2; second++) {
      if (second > first + 1 && nums[second] == nums[second - 1]) {
        continue;
      }
      int low = second + 1;
      int high = n - 1;
      while (low < high) {
        long long sum =
            (long long)nums[first] + nums[second] + nums[low] + nums[high];
        if (sum == target) {
          quadlets.push_back(
              {nums[first], nums[second], nums[low], nums[high]});
          low++;
          high--;
          while (low < high && nums[low] == nums[low - 1]) {
            low++;
          }
          while (low < high && nums[high] == nums[high + 1]) {
            high--;
          }
        } else if (sum > target) {
          high--;
        } else {
          low++;
        }
      }
    }
  }
  return quadlets;
}

int main() {
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  vector<vector<int>> quadlet = find_IV_Sum(nums, 0);
  cout << "The Quadlets Are : " << endl;
  for (vector<int> quad : quadlet) {
    for (int num : quad) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}