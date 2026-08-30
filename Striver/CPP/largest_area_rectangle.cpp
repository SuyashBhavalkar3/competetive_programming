#include <algorithm>
#include <iostream>
#include <stack>
#include<vector>

using namespace std;

int largestRectangleArea(vector<int> &heights) {
  int maxArea = -1;
  stack<int> st;
  int n = heights.size();
  for (int i = 0; i < n; i++) {
    while (!st.empty() && heights[st.top()] > heights[i]) {
      int ele = heights[st.top()];
      st.pop();
      int pse = st.empty() ? -1 : st.top();
      maxArea = max(maxArea, ele * (i - pse - 1));
    }
    st.push(i);
  }
  while (!st.empty()) {
    int nse = n;
    int ele = heights[st.top()];
    st.pop();
    int pse = st.empty() ? -1 : st.top();
    maxArea = max(maxArea, ele * (nse - pse - 1));
  }
  return maxArea;
}

int main() {
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  int largest_area = largestRectangleArea(heights);
  cout << "The Largest Area Of Reactangle Is : " << largest_area << endl;
  return 0;
}