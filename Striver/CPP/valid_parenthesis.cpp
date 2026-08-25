#include <iostream>
#include <stack>

using namespace std;

bool isValid(string str) {
  stack<int> st;
  int n = str.size();
  for (int i = 0; i < n; i++) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      st.push(str[i]);
    } else {
      if (st.empty()) {
        return false;
      }
      char top = st.top();
      st.pop();
      if (str[i] == ')' && top == '(' || str[i] == ']' && top == '[' ||
          str[i] == '}' && top == '{') {
        continue;
      } else {
        return false;
      }
    }
  }
  return st.empty();
}

int main() {
  string str1 = "[{()}]";
  bool res = isValid(str1);
  cout << boolalpha;
  cout << "The Provided String is a valid parenthesis : " << res << endl;
}