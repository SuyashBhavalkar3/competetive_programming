// Given a string s, find the length of the longest substring without duplicate characters.

// Look For Reference In the Book-2 On Pg No 137-138


#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int longest_substring(string s){
    int maxlen = 0;
    unordered_map<char, int> map;
    int l = 0, r = 0, n = s.size();
    while(r<n){
        if(map.count(s[r])){
            l = max(l, map[s[r]]+1);
        }
        map[s[r]] = r;
        maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
};

int main(){
    string s = "bbbbb";
    cout<<"The Longest Substring without Repeating Characters Is : "<<longest_substring(s)<<endl;
    return 0;
}