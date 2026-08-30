#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<int> slidingWindowMaximum(vector<int> &nums, int k) {
  deque<int> dq;
  vector<int> res;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    if(!dq.empty() && dq.front()<=i-k){
        dq.pop_front();
    }
    while (!dq.empty() && nums[dq.back()]<=nums[i]) {
        dq.pop_back();
    }
    dq.push_back(i);
    if (i >= k - 1) {
      res.push_back(nums[dq.front()]);
    }
  }
  return res;
};

int main() {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  vector<int> res = slidingWindowMaximum(nums, 3);
  for (int num : res) {
    cout << num << " ";
  }
  return 0;
};