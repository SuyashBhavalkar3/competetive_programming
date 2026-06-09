// Given an array nums of n integers.

// Return the length of the longest sequence of consecutive integers.
// The integers in this sequence can appear in any order.

// Look For Reference In the Book-2 On Pg No 132-133


#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

int longest_sequence(vector<int>& nums){
    // if(nums==nullptr||nums.size()==0)   return 0;
    if(nums.size()==0)   return 0;
    int longest = 1;
    unordered_set<int> set;
    for(int num : nums){
        set.insert(num);
    }
    for(int num : nums){
        if(set.find(num-1)==set.end()){
            int cnt = 1;
            int curr = num;
            while(set.find(curr+1)!=set.end()){
                cnt++;
                curr++;
            }
            longest = max(cnt, longest);
        }
    }
    return longest;
};

int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout<<"The Longest Consecutive Sequence Is : "<<longest_sequence(nums)<<endl;
    return 0;
}