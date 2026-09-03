#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string reverseWordsInString(string str) {
  stringstream ss(str);
  string word;
  vector<string> words;
  string ans = "";
  while (ss >> word) {
    words.push_back(word);
  }
  for (int i = words.size() - 1; i >= 0; i--) {
    ans += words[i];
    if (i != 0) {
      ans += " ";
    }
  }
  return ans;
}

int main() {
  string str = "the sky is blue";
  cout << str << endl;
  string ans = reverseWordsInString(str);
  cout << ans << endl;
  return 0;
}