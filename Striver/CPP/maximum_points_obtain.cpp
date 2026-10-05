#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int maximum_points(vector<int> &cardPoints, int k) {
  int n = cardPoints.size();
  if (n < k) {
    return -1;
  }
  if (n == k) {
    return accumulate(cardPoints.begin(), cardPoints.end(), 0);
  }
  int windowSum = 0;
  for (int i = 0; i < n - k; i++) {
    windowSum += cardPoints[i];
  }
  int maxSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
  cout << "MaxSum : " << maxSum << endl;
  cout << "Window Sum : " << windowSum << endl;
  int maxPoints = maxSum - windowSum;
  cout << "Initial MaxPoints : " << maxPoints << endl;
  int left = 0;
  int right = n - k;
  while (right < n) {
    windowSum += cardPoints[right];
    cout << "right : " << cardPoints[right] << endl;
    right++;
    windowSum -= cardPoints[left]; //[11,49,100,20,86,29,72]
    cout << "left : " << cardPoints[left] << endl;
    left++;
    cout << "Window Sum : " << windowSum << endl;
    maxPoints = max(maxPoints, maxSum - windowSum);
    cout << " MaxPoints : " << maxPoints << endl;
  }
  return maxPoints;
}

int main() {
  vector<int> nums = {11, 49, 100, 20, 86, 29, 72};
  int maxPoints = maximum_points(nums, 4);
  cout << "The Maximum Points We Can Obtain Are : " << maxPoints << endl;
  return 0;
}