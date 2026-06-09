// You are given a sorted array consisting of only integers where every element appears exactly twice,
// except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

// Look For Reference In the Book On Pg No 85-86



#include<iostream>
#include<vector>

using namespace std;

int findRes(vector<int>& nums){
    int low = 0;
    int high = nums.size()-1;
    while(low<=high){
        int pivot = low + (high - low)/2;
        if(nums[pivot]!=nums[pivot+1] && nums[pivot]!=nums[pivot-1]){
            return nums[pivot];
        }
        if(pivot%2==1 && nums[pivot]==nums[pivot-1]||pivot%2==0 && nums[pivot]==nums[pivot+1]){
            low = pivot+1;
        }
        else{
            high = pivot-1;
        }
    }
    return -1;
};

int main(){
    vector<int> nums = {3,3,7,7,10,11,11};
    int res = findRes(nums);
    cout<<"The Variable Occuring only Once Is : "<<res<<endl;
    return 0;
}