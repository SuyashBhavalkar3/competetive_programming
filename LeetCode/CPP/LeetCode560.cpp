// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Look For Reference In the Book-2 On Pg No 140 - 141


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int count_subarrays_with_sum_k(vector<int>& arr, int k){
    int prefix_sum  = 0;
    int count = 0;
    unordered_map<int, int> map;        //To Store HasMap of PrefixSum : Count 
    map[0] = 1;
    for(int i=0;i<arr.size();i++){
        prefix_sum+=arr[i];
        count+=map[prefix_sum-k];
        map[prefix_sum]++;
    }
    return count;
}

int main(){
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    cout<<"The Count of SubArrays with Sum K is : "<<count_subarrays_with_sum_k(arr, k)<<endl;
    return 0;
}