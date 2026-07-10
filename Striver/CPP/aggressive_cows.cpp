#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

bool canWePlace(vector<int> &nums, int k, int mid) {
  int coes = 1;
  int last = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    if ((nums[i] - last) >= mid) {
      coes++;
      last = nums[i];
    }
    if (coes >= k) {
      return true;
    }
  }
  return false;
}

int maxOfMinimumDistanceCows(vector<int> &nums, int k) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int low = 1;
  int high = nums[n - 1] - nums[0];
  int ans = INT_MIN;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (canWePlace(nums, k, mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {0, 3, 4, 7, 10, 9};
  int k = 4;
  int maxOfMin = maxOfMinimumDistanceCows(nums, k);
  cout << "Max Of Minimum Distance Between Cows : " << maxOfMin << endl;
  return 0;
}