#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int>& nums, int tar){
    if (tar<0){
        return 0;
    }
    int cnt = 0;
    int sum = 0;
    int n = nums.size();
    int left = 0;
    for(int i =0 ;i<n;i++){
        sum+=nums[i];
        while(sum>tar){
            sum-=nums[left];
            left++;
        }
        cnt+=i-left+1;
    }
    return cnt;
}

int max_subarrays_with_sumK(vector<int>& nums, int goal){
    return helper(nums, goal) - helper(nums, goal-1);
}

int main(){
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    int max_subarrays = max_subarrays_with_sumK(nums, goal);
    cout<<"The SubArrays With Sum "<<goal<<" are : "<<max_subarrays<<endl;
    return 0;
}