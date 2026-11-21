#include<iostream>
#include <unordered_set>
#include<vector>

using namespace std;

int longest_consecutive_subsequence(vector<int>& nums){
    int maxLength = INT_MIN;
    int currentLength;
    unordered_set<int> numSet(nums.begin(), nums.end());
    for(int num : nums){
        if(numSet.count(num-1)){
            continue;
        }
        currentLength = 1;
        int nextElement = num+1;
        while(numSet.count(nextElement)){
            currentLength++;
            nextElement = nextElement+1;
        }
        maxLength = max(maxLength, currentLength);
        currentLength = 1;
    }
    return maxLength;
}

int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2, 2, 5};
    int lengthOfLongestSequence = longest_consecutive_subsequence(nums);
    cout<<"The Length Of Longest Consecutive subsequence : "<<lengthOfLongestSequence<<endl;
    return 0;
}