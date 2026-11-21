#include<iostream>
#include<vector>

using namespace std;

int Maximum_Ones(vector<int>& nums, int k){
    int maxLen = 0;
    int left = 0;
    int right = 0;
    int zeroes = 0;
    while(right<nums.size()){
        if(nums[right]==0){
            zeroes++;
        }
        if(zeroes>k){
            if(nums[left]==0){
                zeroes--;
            }
            left++;
        }
        if(zeroes<=k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main(){
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int maxLen = Maximum_Ones(nums, 2);
    cout<<"The Length of Maximum Ones With Zeroes FLipped Is : "<<maxLen<<endl;
    return 0;
}