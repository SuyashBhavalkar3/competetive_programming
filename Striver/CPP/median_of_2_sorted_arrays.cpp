#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int findKthElement(vector<int> &nums1, vector<int> &nums2, int n, int m,
                   int k) {
  if (n > m) {
    return findKthElement(nums2, nums1, m, n, k);
  }
  int low = max(0, k - m);
  int high = min(n, k);
  int l1, l2, r1, r2;
  while (low <= high) {
    int cut1 = low + (high - low) / 2;
    int cut2 = k - cut1;
    if (cut1 == 0) {
      l1 = INT_MIN;
    } else {
      l1 = nums1[cut1 - 1];
    }
    if (cut2 == 0) {
      l2 = INT_MIN;
    } else {
      l2 = nums2[cut2 - 1];
    }
    if (cut1 == n) {
      r1 = INT_MAX;
    } else {
      r1 = nums1[cut1];
    }
    if (cut2 == m) {
      r2 = INT_MAX;
    } else {
      r2 = nums2[cut2];
    }
    if (l1 <= r2 && l2 <= r1) {
      return max(l1, l2);
    }
    if (l1 > r2) {
      high = cut1 - 1;
    } else {
      low = cut1 + 1;
    }
  }
  return -1;
}

int main() {
  vector<int> nums1 = {2, 3, 6, 7, 9};
  vector<int> nums2 = {1, 4, 8, 10};
  int KthElement = findKthElement(nums1, nums2, nums1.size(), nums2.size(), 5);
  cout << "The Kth Element From sorted Two arrays is : " << KthElement << endl;
  return 0;
}