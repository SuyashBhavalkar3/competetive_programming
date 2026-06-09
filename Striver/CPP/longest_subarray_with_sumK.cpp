// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k.
// If no such sub-array exists, return 0.

// Look For Reference In the Book-2 On Pg No 135-136


#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int longest_subarray_sum_K(vector<int>& nums, int k){
    unordered_map<int, int> map;
    int maxLen = 0;
    int prefixsum = 0;
    for(int i=0;i<nums.size();i++){
        prefixsum+=nums[i];
        if(prefixsum==k){
            maxLen = max(maxLen, i+1);
        }
        if(map.find(prefixsum-k)!=map.end()){
            maxLen = max(maxLen, i - map[prefixsum-k]);
        }
        if(map.find(prefixsum)==map.end()){
            map[prefixsum] = i;
        }
    }
    return maxLen;
};

int main(){
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    cout<<"The Longest SubArray With Sum K Has Length : "<<longest_subarray_sum_K(nums, k)<<endl;
    return 0;
}