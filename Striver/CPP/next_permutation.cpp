#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> next_permutation(vector<int> &arr) {
  int n = arr.size();
  if (n == 1) {
    return arr;
  }
  int index = -1;
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1]) {
      index = i;
    }
  }
  if (index == -1) {
    reverse(arr.begin(), arr.end());
    return arr;
  }

  for (int i = n - 1; i >= 0; i--) {
    if (arr[index] < arr[i]) {
      int temp = arr[index];
      arr[index] = arr[i];
      arr[i] = temp;
      break;
    }
  }
  reverse(arr.begin() + index + 1, arr.end());
  return arr;
}

int main() {
  vector<int> arr = {2, 4, 3, 1};
  vector<int> res = next_permutation(arr);
  for (int num : res) {
    cout << num << " ";
  }
  return 0;
}