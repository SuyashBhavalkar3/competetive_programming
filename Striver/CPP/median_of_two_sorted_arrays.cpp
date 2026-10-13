#include <iostream>
#include <vector>

using namespace std;

int Median_Two_Sorted_Arrays(vector<int> &nums1, vector<int> &nums2) {
  if (nums1.size() > nums2.size()) {
    return Median_Two_Sorted_Arrays(nums2, nums1);
  }
  int n1 = nums1.size();
  int n2 = nums2.size();
  int low = 0;
  int high = n1;
  while (low <= high) {
    int cut1 = low + (high - low) / 2;
    int cut2 = (n1 + n2 + 1) / 2 - cut1;
    int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
    int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
    int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
    int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
    if (l1 <= r2 && l2 <= r1) {
      if ((n1 + n2) % 2 == 0) {
        return (max(l1, l2) + min(r1, r2)) / 2;
      } else {
        return max(l1, l2);
      }
    } else {
      if (l1 > r2) {
        high = cut1 - 1;
      } else {
        low = cut1 + 1;
      }
    }
  }
  return -1;
}

int main() {
  vector<int> nums1 = {1, 3, 4, 7, 10, 12};
  vector<int> nums2 = {2, 3, 6, 15};
  int median = Median_Two_Sorted_Arrays(nums1, nums2);
  cout << "The Median Of Two Sorted Arrays Is : " << median << endl;
  return 0;
}