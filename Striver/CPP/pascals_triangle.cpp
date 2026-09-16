#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pascals_triangle(int n) {
  if (n == 0) {
    return {{}};
  }
  if (n == 1) {
    return {{1}};
  }
  vector<vector<int>> result;
  vector<int> prev = {1};
  result.push_back(prev);
  for (int i = 2; i <= n; i++) {
    vector<int> curr;
    curr.push_back(1);
    int n = prev.size();
    for (int i = 1; i < n; i++) {
      curr.push_back(prev[i] + prev[i - 1]);
    }
    curr.push_back(1);
    result.push_back(curr);
    prev = curr;
  }
  return result;
}

int main() {
  int n = 5;
  vector<vector<int>> result = pascals_triangle(n);
  for (vector<int> arr : result) {
    cout << "{";
    for (int num : arr) {
      cout << num << " ";
    }
    cout << "}";
    cout << endl;
  }
  return 0;
}