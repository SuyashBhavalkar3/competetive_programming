// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Look For Reference In the Book-2 On Pg No 19


#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int max_sumof_subarray(vector<int>& arr){
    int max_sum = INT_MIN;
    int curr_sum = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        curr_sum+=arr[i];
        max_sum = max(curr_sum, max_sum);
        if(curr_sum<0){
            curr_sum = 0;
        }
    }
    return max_sum;
};

int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<"Maximmum Sum Of SubArray Is : "<<max_sumof_subarray(arr)<<endl;
    return 0;
}
