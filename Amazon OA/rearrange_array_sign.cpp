#include <iostream>
#include <vector>

using namespace std;

vector<int> ReArrange(vector<int>& nums){
    vector<int> ans(nums.size());
    int n = nums.size();
    int posIndex = 0;
    int negIndex = 1;
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            ans[posIndex] = nums[i];
            posIndex+=2;
        }
        else{
            ans[negIndex] = nums[i];
            negIndex+=2;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {2, 4, 5, -1, -3, -4};
    vector<int> ans = ReArrange(nums);
    for(int num : ans){
        cout<<num<<" ";
    }
    return 0;
}