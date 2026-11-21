#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int>&nums, int goal){
    if(goal<0){
        return 0;
    }
    int left = 0;
    int right = 0;
    int sum = 0;
    int cnt = 0;
    while(right < nums.size()){
        sum+=nums[right];
        while(sum>goal){
            sum-=nums[left];
            left++;
        }
        cnt+=right - left + 1;
        right++;
    }
    return cnt;
}

int Subarrays_with_sumK(vector<int>& nums, int goal){
    return helper(nums, goal) - helper(nums, goal-1);
}

int main(){
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    int subarrays = Subarrays_with_sumK(nums, goal);
    cout<<"The Number Of Subarrays With Sum K Are : "<<subarrays<<endl;
    return 0;
}