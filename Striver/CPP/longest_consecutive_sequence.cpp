#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

int longest_Consecutive_Sequence(vector<int>& nums){
    int longestLength = 0;
    unordered_set<int> values(nums.begin(), nums.end());
    for(int value : values){
        if(values.count(value-1)){
            continue;
        }
        int currentLength = 1;
        int nextVal = value + 1;
        while(values.count(nextVal)){
            currentLength++;
            nextVal++;
        }
        longestLength = max(longestLength, currentLength);
    }
    return longestLength;
}

int main(){
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int longest_sequence = longest_Consecutive_Sequence(nums);
    cout<<"The Longest Consecutive Length Is : "<<longest_sequence<<endl;
    return 0;
}