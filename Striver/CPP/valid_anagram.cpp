#include <ios>
#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string str, string tar) {
  if (str.size() == 0 || tar.size() == 0) {
    return false;
  }
  int n = str.size();
  int m = tar.size();
  if (n != m) {
    return false;
  }
  vector<int> freq(26);
  for (int i = 0; i < n; i++) {
    freq[str[i] - 'a']++;
  }
  for (int i = 0; i < m; i++) {
    freq[tar[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++) {
    if (freq[i] != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  string str = "anagram";
  string target = "nagaram";
  cout << boolalpha;
  cout << "The target string " << target << " is a anagram of string " << str
       << " is : " << isAnagram(str, target) << endl;
  return 0;
}