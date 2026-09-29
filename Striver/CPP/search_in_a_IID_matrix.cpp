#include <ios>
#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int n = matrix.size();
  if (n == 0 || matrix[0].size() == 0) {
    return false;
  }
   int m = matrix[0].size();
  int row = 0;
  int col = m - 1;
  while (row < n && col>=0) {
    if (matrix[row][col] == target) {
      return true;
    }
    if (target < matrix[row][col]) {
      col--;
    } else {
      row++;
    }
  }
  return false;
}

int main() {
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
  cout << boolalpha;
  bool existInIIDMatrix = searchMatrix(matrix, 30);
  cout << "The Required Element Exists In Matrix : " << existInIIDMatrix
       << endl;
  return 0;
}