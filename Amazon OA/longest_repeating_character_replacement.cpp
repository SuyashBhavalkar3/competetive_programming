#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int LengthLongestRepeatingCharacterReplacement(string str, int k){
    int maxLen = 0;
    vector<int> freq(26, 0);
    int maxFreq = 0;
    int left = 0;
    int right = 0;
    while(right< str.size()){
        freq[str[right]-'A']++;
        maxFreq = max(maxFreq, freq[str[right]-'A']);
        if((right-left+1) - maxFreq > k){
            freq[str[left]-'A']--;
            left++;
        }
        if(((right-left+1) - maxFreq)<=k){
            maxLen = max(maxLen, right - left +1);
        }
        right++;
    }
    return maxLen;
}

int main(){
    string str = "AABABBA";
    int maxLen = LengthLongestRepeatingCharacterReplacement(str, 1);
    cout<<"The Maximum Length Of Longest Repeating Character Replacement Substring : "<< maxLen<<endl;
    return 0;
}