#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int Minimum_In_Rotated_Array(vector<int>& nums){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high - low)/2;
        // cout<<"Mid Is : "<<nums[mid]<<endl;
        if(nums[low]<=nums[mid]){
            // cout<<"Ans Is From IF: "<<nums[ans]<<endl;
            // cout<<"Low Is : "<<nums[low]<<endl;
            // cout<<"Mid Is : "<<nums[mid]<<endl;
            // cout<<"High Is : "<<nums[high]<<endl;
            ans = min(ans, nums[low]);
            low = mid+1;
            // cout<<"New Low : "<<nums[low]<<endl;
            // cout<<"Done..."<<endl;
        }
        else{
            // cout<<"Ans Is From IF: "<<nums[ans]<<endl;
            // cout<<"Low Is : "<<nums[low]<<endl;
            // cout<<"Mid Is : "<<nums[mid]<<endl;
            // cout<<"High Is : "<<nums[high]<<endl;
            ans = min(ans, nums[mid]);
            high = mid - 1;
            // cout<<"New High : "<<nums[high]<<endl;
            // cout<<"Done..."<<endl;
        }
    }
    return ans;
}

int main(){
    vector<int> arr ={2, 5, 6, 7, 0, 1, 2};
    int minIndex = Minimum_In_Rotated_Array(arr);
    cout<<"The Minimum Element Is : "<<minIndex<<endl;
    return 0;
}