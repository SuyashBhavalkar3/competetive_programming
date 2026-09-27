#include<iostream>
#include<vector>

using namespace std;

int find_minimum(vector<int>& nums){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[low]<=nums[mid]){
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int min = find_minimum(nums);
    cout<<"The Minimum in rotated sorted array is : "<<min<<endl;
    return 0;
}