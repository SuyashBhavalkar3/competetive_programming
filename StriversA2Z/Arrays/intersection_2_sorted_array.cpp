#include <iostream>
#include <vector>

using namespace std;

vector<int> findIntersection(vector<int> &nums1, vector<int> nums2) {
  int n = nums1.size();
  int m = nums2.size();
  int i = 0;
  int j = 0;
  vector<int> unionResult;
  while (i < n && j < m) {
    int currValue;
    bool assigned = false;
    if (nums1[i] < nums2[j]) {
      i++;
    } else if (nums2[j] < nums1[i]) {
      j++;
    } else {
      currValue = nums1[i];
      assigned = true;
      i++;
      j++;
    }
    if ((unionResult.empty() || unionResult.back() != currValue) && assigned == true) {
      unionResult.push_back(currValue);
    }
  }
  return unionResult;
}

int main() {
  vector<int> nums1 = {1, 2, 2, 3, 3};
  vector<int> nums2 = {2, 3, 3, 4, 5, 7};
  vector<int> answer = findIntersection(nums1, nums2);
  for (int value : answer) {
    cout << value << " ";
  }
  return 0;
}