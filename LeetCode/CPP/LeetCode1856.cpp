// The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

// For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
// Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums.
// Since the answer may be large, return it modulo 109 + 7.

// Note that the min-product should be maximized before performing the modulo operation.
// Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.

// A subarray is a contiguous part of an array.

// Look For Reference In the Book On Pg No 158-159


#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int maxProductMinSubArray(vector<int>& nums){
    int n = nums.size();
    vector<long long> prefix(n+1);
    vector<int> right(n, n);
    vector<int> left(n,-1);
    for(int i=0;i<n;i++){
        prefix[i+1] = prefix[i] + nums[i];
    }
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]){
            right[st.top()] = i;
            st.pop();
        }
        if(!st.empty()){
            left[i] = st.top();
        }
        st.push(i);
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        int leftl = left[i] + 1;
        int righr = right[i];
        long long prefixSum = prefix[righr] - prefix[leftl];
        ans = max(ans, prefixSum*nums[i]);
    }
    return (int)(ans%1000000007);
}

int main(){
    vector<int> arr = {3,1,5,6,4,2};
    cout<<maxProductMinSubArray(arr)<<endl;
}