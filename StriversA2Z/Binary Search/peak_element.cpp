#include<iostream>
#include<vector>

using namespace std;

int Find_Peak_Element(vector<int>& nums){
    int low = 0;
    int high = nums.size()-1;
    while(low<high){
        int mid = low + (high - low)/2;
        if(mid!=0 && mid!=nums.size()-1 && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
            return mid;
        }
        else if(mid==0 && nums[mid]>nums[mid+1]){
            return mid;
        }
        else if(mid==nums.size()-1 && nums[mid]>nums[mid-1]){
            return mid;
        }
        else if(nums[mid]<nums[mid+1]){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return -1;
}

int main(){
    vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int peakElement = Find_Peak_Element(elements);
    cout<<"The Peak Element In The Array Is : "<<peakElement<<endl;
    return 0;
}