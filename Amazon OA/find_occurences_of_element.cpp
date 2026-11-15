#include<iostream>
#include<vector>

using namespace std;

int Upper_Bound(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid]>target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int Lower_Bound(vector<int>& nums, int target){
    int n = nums.size();
    int ans = n;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid]>=target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int FInd_Occurences(vector<int>& nums, int target){
    int lower_bound = Lower_Bound(nums, target);
    int upper_bound = Upper_Bound(nums, target);
    return upper_bound - lower_bound;
}

int main(){
    vector<int> nums = {0, 1, 1, 1, 2, 3};
    int target = 1;
    int occurences = FInd_Occurences(nums, target);
    cout<<"The Number Of Occurences Of Given Element Are : "<<occurences<<endl;
    return 0;
}