#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int allocatePage(vector<int>& nums, int mid, int m){
    int n = 1;
    int pages = 0;
    for(int num : nums){
        pages+=num;
        cout<<pages<<endl;
        if(pages>mid){
            n++;
            pages = num;
        }
    }
    return n;
}

int allocateMinimumPages(vector<int>& nums, int m){
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    cout<<low<<" "<<high<<endl;
    while(low<=high){
        int mid = low + (high - low)/2;
        cout<<mid<<endl;
        if(allocatePage(nums, mid, m)>m){
            low = mid + 1;
            cout<<low<<endl;
        }
        else{
            high = mid - 1;
            cout<<high<<endl;
        }
    }
    cout<<low<<endl;
    return low;
}

int main(){
    vector<int> nums = {12, 34, 67, 90};
    int m = 2;
    int min = allocateMinimumPages(nums, m);
    if(min!=-1){
        cout<<"The Minimum Number Of Pages We Can Allocate Are : "<<min<<endl;
    }
}