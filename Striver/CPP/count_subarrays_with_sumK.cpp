#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int count_subarrays(vector<int> &nums, int target) {
  int cnt = 0;
  unordered_map<int, int> prefixMap;
  int sum = 0;
  prefixMap[0] = 1;
   cout<<"Putted "<< sum<<endl;
  for (int num : nums) {
    sum += num;
    int needed = sum - target;
    cout << "Needed : " << needed << endl;
    if (prefixMap.find(needed) != prefixMap.end()) {
      cnt += prefixMap[needed];
    }
    prefixMap[sum]++;
    cout<<"Putted "<< sum<<endl;
  }
  return cnt;
}

int main() {
  vector<int> nums = {3, 1, 2, 4};
  int cnt = count_subarrays(nums, 6);
  cout << "The Number Of Subarrays With Sum K Is : " << cnt << endl;
  return 0;
}