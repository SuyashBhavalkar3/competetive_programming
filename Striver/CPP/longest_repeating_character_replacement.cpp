#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int characterReplacement(string str, int k) {
  int maxLen = 0;
  int maxFreq = 0;
  int currLength = 0;
  int left = 0;
  int right = 0;
  vector<int> freq(26, 0);
  for (char ch : str) {
    int idx = ch - 'A';
    freq[idx]++;
    maxFreq = max(maxFreq, freq[idx]);
    currLength = right - left + 1;
    if (currLength - maxFreq > k) {
      freq[str[left] - 'A']--;
      left++;
    }
    currLength = right - left + 1;
    maxLen = max(maxLen, currLength);
    right++;
  }
  return maxLen;
}

int main() {
  string str = "AABABBA";
  int result = characterReplacement(str, 1);
  cout << "The Longest Repeating Character After Replacement Has Count : "
       << result << endl;
  return 0;
}