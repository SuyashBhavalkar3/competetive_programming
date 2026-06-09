// You are given a string s consisting of lowercase English letters.

// Return an integer denoting the maximum number of substrings you can split s
// into such that each substring starts with a distinct character (i.e., no two substrings start with the same character).

// Look For Reference In the Book-2 On Pg No 2


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int getDistinct(string str){
    vector<int> distinctCharacters(26, 0);
    for(char ch : str){
        distinctCharacters[ch-'a']++;
    }
    int cnt = 0;
    for(int num : distinctCharacters){
        if(num!=0)  cnt++;
    }
    return cnt;
}

int main(){
    string str = "abcd";
    cout<<getDistinct(str)<<endl;
    return 0;
}