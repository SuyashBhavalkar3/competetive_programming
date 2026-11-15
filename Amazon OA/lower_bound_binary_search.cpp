// Element>=X is lower bound on binary search

#include<iostream>
#include<vector>

using namespace std;

int Lower_Bound_BS(vector<int>& nums, int x){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid]>=x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {3, 5, 8, 15, 19};
    int x = 9;
    int lower_bound = Lower_Bound_BS(nums, x);
    cout<<"The Lower Bound On Binary Search On Given X("<<x<<") is "<<nums[lower_bound]<<" And is At Index : "<<lower_bound<<endl;
    return 0;
}