// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Look For Reference In the Book-2 On Pg No 80-81


#include<iostream>
#include<vector>

using namespace std;

int longestCommonSubSequence(string text1, string text2){
    int n = text1.size();
    int m = text2.size();
    vector<int> curr(m+1, 0);
    vector<int> prev(m+1, 0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1] == text2[j-1]){
                curr[j] = prev[j-1]+1;
            }
            else{
                curr[j] = max(curr[j-1], prev[j]);
            }
        }
        prev = curr;
        fill(curr.begin(), curr.end(), 0);
    }
    return prev[m];
};

int main(){
    string text1 = "abcde";
    string text2 = "ace";
    cout<<"The longest common subsequence is: "<<longestCommonSubSequence(text1, text2);
    return 0;
}