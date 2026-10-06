#include<iostream>
#include<vector>

using namespace std;

int max_Ones(vector<int>& nums, int k){
    int maxOnes = 0;
    int zeroes = 0;
    int left = 0;
    int right = 0;
    int n = nums.size();
    while(right < n){
        if(nums[right]==0){
            zeroes++;
        }
        if(zeroes>k){
            if(nums[left]==0){
                zeroes--;
            }
            left++;
        }
        maxOnes = max(maxOnes, right - left + 1);
        right++;
    }
    return maxOnes;
}

int main(){
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int max_ones = max_Ones(nums, 2);
    cout<<"The Maximum Ones Consecutively Are : "<<max_ones<<endl;
    return 0;
}