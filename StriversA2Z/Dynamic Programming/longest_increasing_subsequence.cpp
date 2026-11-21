#include <iostream>
#include <vector>

using namespace std;

int Find_LB(int ele, vector<int>& ans){
    int low = 0;
    int high = ans.size()-1;
    int idx = -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(ans[mid]>=ele){
            idx = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return idx;
}

int longest_common_substring(vector<int>& nums){
    int n = nums.size();
    if(n<2){
        return n;
    }
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(nums[i]>ans.back()){
            ans.push_back(nums[i]);
        }
        else{
            int idx = Find_LB(nums[i], ans);
            ans[idx] = nums[i];
        }
    }
    return ans.size();
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int lis = longest_common_substring(nums);
    cout<<"The Longest Increasing Subsequemce Is : "<<lis<<endl;
    return 0;
}