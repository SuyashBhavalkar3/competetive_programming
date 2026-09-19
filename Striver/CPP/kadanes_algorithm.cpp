#include <iostream>
#include <vector>

using namespace std;

int kadanesAlgorithm(vector<int> &nums) {
  int max = INT_MIN;
  int sum = 0;
  for (int num : nums) {
    sum += num;
    if (sum > max) {
      max = sum;
    }
    if (sum < 0) {
      sum = 0;
    }
  }
  return max;
}

int main() {
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int result = kadanesAlgorithm(arr);
  cout << "The maximum sub-array is : " << result << endl;
  return 0;
}