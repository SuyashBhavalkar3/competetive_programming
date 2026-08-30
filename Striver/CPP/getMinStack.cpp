#include <climits>
#include <iostream>
#include <stack>

using namespace std;

class minStack {
  stack<int> st;
  int min = INT_MAX;

public:
  minStack() {}
  void doPush(int val) {
    if (st.empty()) {
      min = val;
      st.push(val);
      return;
    }
    if (min < val) {
      st.push(val);
      return;
    }
    st.push(2 * val - min);
    min = val;
  }
  void getPop() {
    int ele = st.top();
    st.pop();
    if (ele < min) {
      min = (2 * min - ele);
    }
  }
  int getTop() {
    int ele = st.top();
    if (ele < min) {
      return min;
    }
    return ele;
  }
  int getMin() { return min; }
};

int main() {
  minStack s;
  s.doPush(-2);
  s.doPush(0);
  s.doPush(-3);
  cout << s.getMin() << " ";
  s.getPop();
  cout << s.getTop() << " ";
  s.getPop();
  cout << s.getMin();
}