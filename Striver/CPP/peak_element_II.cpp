#include <iostream>
#include <vector>

using namespace std;

int findMaxEle(vector<vector<int>> &matrix, int mid, int n) {
  int index = -1;
  int max_ele = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (matrix[i][mid] > max_ele) {
      max_ele = matrix[i][mid];
      index = i;
    }
  }
  return index;
}

pair<int, int> peakElementII(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int low = 0;
  int high = m - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int maxEle = findMaxEle(matrix, mid, n);
    int left = mid - 1 >= 0 ? matrix[maxEle][mid - 1] : -1;
    int right = mid + 1 < m ? matrix[maxEle][mid + 1] : -1;
    if (matrix[maxEle][mid] > left && matrix[maxEle][mid] > right) {
      return {maxEle, mid};
    } else if (matrix[maxEle][mid] < left) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return {-1, -1};
}

int main() {
  vector<vector<int>> matrix = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
  pair<int, int> peakPair = peakElementII(matrix);
  cout << "The Peek Pair Is : " << peakPair.first << "," << peakPair.second
       << endl;
  return 0;
}