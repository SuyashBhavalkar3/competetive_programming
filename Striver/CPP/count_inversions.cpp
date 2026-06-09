// Count Inversions

// Given an integer array nums. Return the number of inversions in the array.

// Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// It indicates how close an array is to being sorted.

// A sorted array has an inversion count of 0.

// An array sorted in descending order has maximum inversion.

// Look For Reference In the Book-2 On Pg No 108-109


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
   long long int merge_inversions(vector<int>& nums, long long int low, long long pivot, long long int high){
    long long cnt = 0;
        int l1 = pivot-low+1;
        int r1 = high-pivot;
        vector<long long int> L(l1), R(r1);
        for(long long int i=0;i<l1;i++){
            L[i] = nums[low+i];
        }
        for(long long int i=0;i<r1;i++){
            R[i] = nums[pivot+i+1];
        }
        long long int i = 0, j = 0, k = low;
        while(i<l1 && j<r1){
            if(L[i]<=R[j]){
                nums[k++] = L[i++];
            }
            else{
                nums[k++] = R[j++];
                cnt+=l1-i;
            }
        }
        while(i<l1){
            nums[k++] = L[i++];
        }
        while(j<r1){
            nums[k++] = R[j++];
        }
        return cnt;
    }
   long long int inversions_(vector<int>& nums, long long int low, long long int high){
        long long cnt = 0;
        if(low>=high)   return cnt;
        long long int pivot = low + (high-low)/2;
        cnt+=inversions_(nums, low, pivot);
        cnt+=inversions_(nums, pivot+1, high);
        cnt+=merge_inversions(nums, low, pivot, high);
        return cnt;
    }
   long long int numberOfInversions(vector<int>& nums) {
        return inversions_(nums, 0, nums.size()-1);
    }
};


int main(){
    vector<int> arr = {5, 3, 2, 1, 4};
    int n = arr.size();
    Solution sol;
    cout<<"No. of Inversions In The Array Are : " << sol.numberOfInversions(arr);
    return 0;
}

