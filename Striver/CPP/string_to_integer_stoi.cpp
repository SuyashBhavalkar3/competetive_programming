#include <iostream>

using namespace std;

int string_to_integer(string str) {
  int i = 0;
  int n = str.size();
  while (i < n && str[i] == ' ') {
    i++;
  }
  int sign = 1;
  if (i < n && (str[i] == '+' || str[i] == '-')) {
    if (str[i] == '-') {
      sign = -1;
    }
    i++;
  }
  long long num = 0;
  while (i < n && isdigit(str[i])) {
    num = num * 10 + (str[i] - '0');
    if (sign * num > INT_MAX) {
      return INT_MAX;
    }
    if (sign * num < INT_MIN) {
      return INT_MIN;
    }
    i++;
  }
  return sign * num;
}

int main() {
  string str = "1337c0d3";
  int res = string_to_integer(str);
  cout << "The Result After string to integer is : " << res << endl;
}