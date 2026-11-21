#include<iostream>
#include<unordered_map>

using namespace std;

int longest_substring(string str){
    int n = str.size();
    if(n<=1){
        return n;
    }
    unordered_map<char, int> map;
    int maxlen = 0;
    int right = 0;
    int left = 0;
    while(right<n){
        if(map.find(str[right])!=map.end()){
            if(map[str[right]]>=left){
                left = map[str[right]]+1;
            }
        }
        map[str[right]] = right;
        maxlen = max(maxlen, right - left +1);
        right++;
    }
    return maxlen;
}

int main(){
    string str = "abcabcbb";
    int resultLen = longest_substring(str);
    cout<<"The Length Of Longest Substring Without Repeating Character Is : "<<resultLen<<endl;
    return 0;
}