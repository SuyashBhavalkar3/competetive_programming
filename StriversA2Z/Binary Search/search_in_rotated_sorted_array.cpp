#include<iostream>
#include<vector>

using namespace std;

int Search_Rotated_Array(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(nums[mid]<target && target<=nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int idx = Search_Rotated_Array(arr, target);
    cout<<"The Index At Which Target Is Present Is : "<<idx<<endl;
    return 0;
}