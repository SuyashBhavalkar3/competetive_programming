// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Look For Reference In the Book On Pg No 47-48

#include<iostream>
#include<vector>

using namespace std;

bool isAnagram(string s, string t){
    vector<int> count(26);
    for(char ch : s){
        count[ch-'a']++;
    }
    for(char ch : t){
        count[ch-'a']--;
    }
    for(int nums : count){
        if(nums!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "anagram";
    string t = "nagaram";
    bool res = isAnagram(s, t);
    cout<<boolalpha;
    cout<<"Two Strings Are Anagram : "<<res<<endl;
}