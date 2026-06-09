// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Look For Reference In the Book On Pg No 149


#include<iostream>
#include<vector>

using namespace std;

bool is_same_array(vector<int>& freq, vector<int>& windowFreq){
    for(int i=0;i<26;i++){
        if(freq[i]!=windowFreq[i])  return false;
    }
    return true;
};

bool has_permutation(string s1, string s2){
    vector<int> freq(26, 0);
    for(char ch : s1){
        freq[ch-'a']++;
    }
    int windowSize = s1.size();
    for(int i=0;i<s2.size();i++){
        vector<int> windowFreq(26, 0);
        int windowIdx = 0, idx = i;
        while(windowIdx<windowSize&&idx<s2.size()){
            windowFreq[s2[idx]-'a']++;
            windowIdx++;
            idx++;
        }
        if(is_same_array(freq, windowFreq)) return true;
    }
    return false;
};

int main(){
    cout<<"Enter S1 : ";
    string s1, s2;
    cin>>s1;
    cout<<"Enter S2 : ";
    cin>>s2;
    cout<<boolalpha;
    cout<<has_permutation(s1, s2)<<endl;
    return 0;
}