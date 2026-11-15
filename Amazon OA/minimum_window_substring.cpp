#include<iostream>
#include<vector>

using namespace std;

string Minimum_Window_Substring(string s, string t){
    vector<int> needed(128, 0);
    vector<int> currentSubstring(128, 0);
    for(char ch : t){
        needed[ch-'a']++;
    }
    int substrSize = t.size();
    int mainStringSize = s.size();
    int left = 0;
    int right = 0;
    int matched = 0;
    int minIndex = mainStringSize;
    int minLength = mainStringSize;
    while(right<mainStringSize){
        currentSubstring[s[right]-'a']++;
        if(needed[s[right]-'a']>0 && currentSubstring[s[right]-'a']<=needed[s[right]-'a']){
            matched++;
        }
        while(matched==substrSize){
            if(right - left + 1 < minLength){
                minLength = right - left + 1;
                minIndex = left;
            }
            currentSubstring[s[left]-'a']--;
            if(needed[s[left]-'a']>0 && currentSubstring[s[left]-'a']<needed[s[left]-'a']){
                matched--;
            }
            left++;
        }
        right++;
    }
    return s.substr(minIndex,minIndex+minLength);
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string minWindowSubstring = Minimum_Window_Substring(s, t);
    cout<<"The Minimum Window Substring Is : "<<minWindowSubstring<<endl;
    return 0;
}