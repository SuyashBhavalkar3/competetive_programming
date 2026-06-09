// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// Look For Reference In the Book On Pg No 73


#include<iostream>
#include<vector>
#include<string>
using namespace std;

int findUnique(string s){
    int n = s.size();
    vector<int> freq(26);
    for(char c:s){
        freq[c-'a']++;
    }
    for(int i=0;i<n;i++){
        if(freq[s[i]-'a']==1)   return i;
    }
    return -1;
};

int main(){
    string str = "loveleetcode";
    int res = findUnique(str);
    cout<<"First Non Repeating Character Is At : "<<res<<endl;
};