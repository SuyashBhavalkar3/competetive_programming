#include<iostream>
#include<vector>

using namespace std;

int ceil_array(vector<int>& nums, int x){
     int low = 0;
    int high = nums.size()-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid]>=x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int floor_array(vector<int>& nums, int x){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid]<=x){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

vector<int> Floor_And_Ceil_Array(vector<int>& nums, int x){
    return {floor_array(nums, x), ceil_array(nums, x)};
}

int main(){
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;
    vector<int> floorAndCeil = Floor_And_Ceil_Array(arr, x);
    cout<<"The Floor An Ceil Of Given X ("<<x<<") Are "<<arr[floorAndCeil[0]]<<" and "<<arr[floorAndCeil[1]]<<" Present at index "<<floorAndCeil[0]<<" and "<<floorAndCeil[1]<<" respectively"<<endl;
    return 0;
}