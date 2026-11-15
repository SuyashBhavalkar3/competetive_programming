#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int Find_N_rotated(vector<int>& nums){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    int minIndex = -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[low]<=nums[mid]){
            if(nums[low]<ans){
                ans = nums[low];
                minIndex = low;
            }
            low = mid+1;
        }
        else{
            if(nums[mid]<ans){
                ans = nums[mid];
                minIndex = mid;
            }
            high = mid - 1;
        }
    }
    return minIndex;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int nTimesRotated = Find_N_rotated(arr);
    cout<<"The Number Of Times Array Is Rotated : "<<nTimesRotated<<endl;
    return 0;
}