#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Find_Minimum_Substring(string str, string t) {
  int minIndex = -1;
  int minLength = INT_MAX;
  int left = 0;
  int right = 0;
  int n = str.size();
  int cnt = t.size();
  int matched = 0;
  vector<int> neededForSubstring(256, 0);
  vector<int> currentSubstring(256, 0);
  for (char ch : t) {
    neededForSubstring[ch]++;
  }
  while (right < n) {
    currentSubstring[str[right]]++;
    if (neededForSubstring[str[right]] > 0 &&
        currentSubstring[str[right]] <= neededForSubstring[str[right]]) {
      matched++;
    }
    while (matched == cnt) {
      int currentLength = right - left + 1;
      if (currentLength < minLength) {
        minLength = currentLength;
        minIndex = left;
      }
      currentSubstring[str[left]]--;
      if (neededForSubstring[str[left]] > 0 &&
          currentSubstring[str[left]] < neededForSubstring[str[left]]) {
        matched--;
      }
      left++;
    }
    right++;
  }
  return minIndex == -1 ? " " : str.substr(minIndex, minLength);
}

int main() {
  string strs = "ADOBECODEBANC";
  string t = "ABC";
  string minWindowSubstring = Find_Minimum_Substring(strs, t);
  cout << "The Minimmum Window Substring Is : " << minWindowSubstring << endl;
  return 0;
}