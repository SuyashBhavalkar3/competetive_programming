#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int longest_substring(string str, int k){
    int maxLen = 0;
    unordered_map<char, int> map;
    int left = 0;
    int right = 0;
    while(right<str.size()){
        map[str[right]]++;
        if(map.size()>k){
            map[str[left]]--;
            if(map[str[left]]==0){
                map.erase(str[left]);
            }
            left++;
        }
        if(map.size()<=k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main(){
    string str = "aaabbccc";
    int maxLen = longest_substring(str,2);
    cout<<"The Longest Substring With K Distinct Characters : "<<maxLen<<endl;
    return 0;
}