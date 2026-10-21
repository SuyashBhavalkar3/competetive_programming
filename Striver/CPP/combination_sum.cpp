#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>> &all_combinations, vector<int> &combination,
            vector<int> &nums, int target, int idx, int n) {
  if (target == 0) {
    all_combinations.push_back(combination);
    return;
  }
  if (target < 0) {
    return;
  }
  for (int i = idx; i < n; i++) {
    if (nums[i] > target) {
      continue;
    }
    combination.push_back(nums[i]);
    helper(all_combinations, combination, nums, target - nums[i], i, n);
    combination.pop_back();
  }
}

vector<vector<int>> find_combination(vector<int> &nums, int target) {
  vector<vector<int>> all_combinations;
  vector<int> combination;
  helper(all_combinations, combination, nums, target, 0, nums.size());
  return all_combinations;
}

int main() {
  vector<int> nums = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> combinations = find_combination(nums, target);
  for (vector<int> combination : combinations) {
    cout << "[";
    for (int num : combination) {
      cout << num << " ";
    }
    cout << "]" << endl;
  }
  return 0;
}