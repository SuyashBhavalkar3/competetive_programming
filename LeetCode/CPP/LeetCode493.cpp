// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

// Look For Reference In the Book-2 On Pg No 128-129


#include<iostream>
#include<vector>

using namespace std;

int reverse_pairs(vector<int>& nums, int low, int mid, int high){
    int cnt = 0;
    int jm = mid+1;
    for(int i=low;i<=mid;i++){
        while(jm<=high && (long)nums[i]>(long)2*nums[jm]){
            jm++;
        }
        cnt+=jm-(mid+1);
    }
    int l1 = mid - low + 1;
    int r1 = high - mid;
    vector<int> L(l1), R(r1);
    for(int i=0;i<l1;i++){
        L[i] = nums[low+i];
    }
    for(int i=0;i<r1;i++){
        R[i] = nums[mid + i + 1];
    }
    int i = 0, j = 0, k = low;
    while(i<l1 && j<r1){
        if(L[i]<=R[j]){
            nums[k++] = L[i++];
        }
        else{
            nums[k++] = R[j++];
        }
    }
    while(i<l1){
        nums[k++] = L[i++];
    }
    while(j<r1){
        nums[k++] = R[j++];
    }
    return cnt;
};

int rev_pair(vector<int>&nums, int low, int high){
    int cnt = 0;
    if(low>=high)   return cnt;
    int pivot = low + (high - low)/2;
    cnt+=rev_pair(nums, low, pivot);
    cnt+=rev_pair(nums, pivot+1, high);
    cnt+=reverse_pairs(nums, low, pivot, high);
    return cnt;
};

int main(){
    vector<int> nums = {1,3,2,3,1};
    cout<<"The Number Of Reverse Pairs Are : "<<rev_pair(nums, 0, nums.size()-1)<<endl;
    return 0;
}