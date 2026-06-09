// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
// and removing all non-alphanumeric characters, it reads the same forward and backward.
// Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Look For Reference In the Book On Pg No 24-25

#include<iostream>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

bool IsPalindrome(string s){
    int low = 0, high = s.size()-1;
    while(low<high){
        if(!isalnum(s[low])){
            low++;
            continue;
        }
        if(!isalnum(s[high])){
            high--;
            continue;
        }
        if(tolower(s[low])!=tolower(s[high])){
            return false;
        }
        low++;
        high--;
    }
    return true;
}

int main(){
    cout<<"Enter String : ";
    string str;
    getline(cin, str);
    if(!str.empty() && str.back()=='\r')    str.pop_back();
    cout<<"String Is Palindrome : "<<IsPalindrome(str);
    return 0;
}