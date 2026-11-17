#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int Find_Longest_Subarray(vector<int>& nums, int k){
    unordered_map<int, int> map;
    map[0] = 0;
    int sum = 0;
    int maxLength = 0;
    int left = 0;
    int right = 0;
    while(right<nums.size()){
        sum+=nums[right];
        if(sum==k){
            maxLength = max(maxLength, right - left + 1);
        }
        if(sum>k){
            sum-=nums[left];
            left++;
        }
        right++;
    }
    return maxLength;
}

int main(){
    vector<int> nums = {0, 5, 2, 7, 1, 9};
    int k = 15;
    int length = Find_Longest_Subarray(nums, k);
    cout<<"The Longest Subaaray with sum k : "<<length<<endl;
    return 0;
}