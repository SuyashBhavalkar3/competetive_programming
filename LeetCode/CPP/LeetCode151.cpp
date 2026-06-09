// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words.
// The returned string should only have a single space separating the words. Do not include any extra spaces.


// Look For Reference In the Book On Pg No 80-81



#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

string reverseWords(string s){
    istringstream iss(s);
    vector<string> words;
    string word;
    string result;
    while(iss>>word){
        words.push_back(word);
    }
    int n = words.size();
    for(int i=n-1;i>=0;i--){
        result+= words[i];
        if(i!=0)    result+=" ";
    }
    return result;
}

int main(){
    string line = "the sky is blue";
    cout<<"The Reversed Line Is ( "<<reverseWords(line)<<" )"<<endl;
    return 0;
}