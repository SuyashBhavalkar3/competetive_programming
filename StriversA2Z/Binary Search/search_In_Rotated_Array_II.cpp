#include<iostream>
#include<vector>

using namespace std;

bool Search_Rotated_Array_II(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            return true;
        }
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
        }
        else if(nums[low]<=nums[mid]){
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
    return false;
}

int main(){
    vector<int> arr ={2, 5, 6, 7, 0, 1, 2};
    int target = 0;
    bool hasTarget = Search_Rotated_Array_II(arr, target);
    cout<<boolalpha<<"The Current Array Contains The Target ? : "<<hasTarget<<endl;
    return 0;
}