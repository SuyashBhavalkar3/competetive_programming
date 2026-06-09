// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.


// Look For Reference In the Book On Pg No 105-106




#include<iostream>
#include<vector>

using namespace std;

string removeOccurences(string str, string part, int n){
    vector<char> st;
    for(char ch : str){
        st.push_back(ch);
        if(st.size()>=n){
            bool match = true;
            for(int i=0;i<n;i++){
                if(st[st.size()-n+i]!=part[i]){
                    match = false;
                    break;
                }
            }
            if(match){
                int pop_size = n;
                while(pop_size>0){
                    st.pop_back();
                    pop_size--;
                }
            }
        }
    }
    string result;
    for(char ch : st){
        result+=ch;
    }
    return result;
};

int main(){
    string str = "daabcbaabcbc";
    string part = "abc";
    cout<<"String After Removing All Occurences Of Substring : "<<"\""<<removeOccurences(str, part, part.size())<<"\""<<endl;
}