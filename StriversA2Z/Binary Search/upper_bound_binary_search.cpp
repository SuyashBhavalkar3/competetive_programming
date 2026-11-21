// Element>X is upper bound on binary search

#include<iostream>
#include<vector>

using namespace std;

int upper_Bound_BS(vector<int>& nums, int x){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid]>x){
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
    vector<int> nums = {1, 2, 2, 3};
    int x = 2;
    int upper_bound = upper_Bound_BS(nums, x);
    cout<<"The upper Bound On Binary Search On Given X("<<x<<") is "<<nums[upper_bound]<<" And is At Index : "<<upper_bound<<endl;
    return 0;
}