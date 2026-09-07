#include <iostream>
#include <string>

using namespace std;

int indexOfFirstOccurenceString(string haystack, string needle) {
  int n = haystack.size();
  int m = needle.size();
  for (int i = 0; i < n - m + 1; i++) {
    int j = 0;
    while (j < m && (haystack[i + j] == needle[j])) {
      j++;
    }
    if (j == m) {
      return i;
    }
  }
  return -1;
}

int main() {
  string haystack = "sadbutsad";
  string needle = "sad";
  int idx = indexOfFirstOccurenceString(haystack, needle);
  cout << "the first index at which needle string occurs in haystack string is "
          ": "
       << idx << endl;
  return 0;
}