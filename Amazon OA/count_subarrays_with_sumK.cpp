#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int> &nums, int k) {
  unordered_map<int, int> map;
  int sum = 0;
  int cnt = 0;
  map[0] = 1;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    int needed = sum - k;
    if (map.find(needed) != map.end()) {
      cnt += map[needed];
    }
    map[sum]++;
  }
  return cnt;
}

int main() {
  vector<int> nums = {3, 1, 2, 4};
  int count = subarraySum(nums, 6);
  cout << "The count of subarrays for sum k is : " << count << endl;
  return 0;
}