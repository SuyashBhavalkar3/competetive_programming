// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.


// Look For Reference In the Book On Pg No 69-70

#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>

using namespace std;

bool isValid(string str){
    stack<char> st;
    unordered_map<char, char> map = {{')','('},
                                    {']','['},
                                    {'}','{'}};
    for(char c : str){
        if(map.find(c)!=map.end()){
            char topEle = st.empty() ? '#' : st.top();
            if(!st.empty()) st.pop();
            if(topEle!=map[c])  return false;
        }
        else    st.push(c);
    }
    return st.empty();
};

int main(){
    string str = "{[()]}";
    bool res = isValid(str);
    cout<<boolalpha;
    cout<<res<<endl;
    return 0;
}