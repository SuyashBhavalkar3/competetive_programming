#include <iostream>
#include <unordered_map>

using namespace std;

int longest_substring(string str) {
  unordered_map<char, int> mpp;
  int res = 0;
  int l = 0;
  int r = 0;
  int n = str.size();
  while (r < n) {
    if (mpp.find(str[r]) != mpp.end()) {
      l = max(l, mpp[str[r]] + 1);
    }
    res = max(res, r - l + 1);
    mpp[str[r]] = r;
    r++;
  }
  return res;
}

int main() {
  string str = "abcddabac";
  int res = longest_substring(str);
  cout << "The Longest SubString without Repeating Character Is : " << res
       << endl;
  return 0;
}