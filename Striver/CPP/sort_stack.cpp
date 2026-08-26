#include <iostream>
#include <stack>

using namespace std;

void insert(stack<int> &st, int temp) {
  if (st.empty() || st.top() <= temp) {
    st.push(temp);
    return;
  }
  int ele = st.top();
  st.pop();
  insert(st, temp);
  st.push(ele);
}

void sortStack(stack<int> &st) {
    if(st.empty()||st.size()==1){
        return;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);
    insert(st, temp);
}

int main() {
  stack<int> st;
  st.push(2);
  st.push(3);
  st.push(1);
  st.push(4);
  sortStack(st);
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}