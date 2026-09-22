#include <iostream>
#include <vector>

using namespace std;

// 1, 2, 1, 1, 3, 2

vector<int> majority_element_II(vector<int> &nums) {
  int candidate1 = nums[0];
  int candidate2 = nums[1];
  int cnt1 = 0;
  int cnt2 = 0;
  for (int num : nums) {
    if (num == candidate1) {
      cnt1++;
    } else if (num == candidate2) {
      cnt2++;
    } else if (cnt1 == 0) {
      candidate1 = num;
      cout << candidate1 << endl;
      cnt1++;
    } else if (cnt2 == 0) {
      candidate2 = num;
      cout << candidate1 << endl;
      cnt2++;
    } else {
      cnt1--;
      cnt2--;
    }
  }
  cout << candidate1 << endl;
  cout << candidate2 << endl;

  int threshold = nums.size() / 3;
  int c1 = 0;
  int c2 = 0;
  vector<int> ans;
  for (int num : nums) {
    if (num == candidate1) {
      c1++;
    } else if (num == candidate2) {
      c2++;
    }
  }
  if (c1 > threshold) {
    ans.push_back(candidate1);
  }
  if (c2 > threshold) {
    ans.push_back(candidate2);
  }
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 1, 1, 3, 2};
  vector<int> majorityElement = majority_element_II(nums);
  cout << "The Majority Element Are : " << endl;
  for (int num : majorityElement) {
    cout << num << " ";
  }
  return 0;
}