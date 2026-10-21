#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>> &result, vector<int> &combination,
            vector<int> &nums, int target, int idx, int n) {
  if (target == 0) {
    result.push_back(combination);
    return;
  }
  if (target < 0) {
    return;
  }

  for (int i = idx; i < n; i++) {
    if (nums[i] > target) {
      continue;
    }
    if (i > idx && nums[i] == nums[i - 1]) {
      continue;
    }
    combination.push_back(nums[i]);
    helper(result, combination, nums, target - nums[i], i + 1, n);
    combination.pop_back();
  }
}

vector<vector<int>> combination_Sum_ii(vector<int> &nums, int target) {
  vector<vector<int>> result;
  vector<int> combination;
  sort(nums.begin(), nums.end());
  helper(result, combination, nums, target, 0, nums.size());
  return result;
}

int main() {
  vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  vector<vector<int>> all_sets = combination_Sum_ii(nums, target);
  for (vector<int> combination : all_sets) {
    cout << "[ ";
    for (int num : combination) {
      cout << num << " ";
    }
    cout << "]" << endl;
  }
  return 0;
}