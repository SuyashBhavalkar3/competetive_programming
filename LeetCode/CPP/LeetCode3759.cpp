// You are given an integer array nums of length n and an integer k.

// An element in nums is said to be qualified if there exist at least k elements in the array that are strictly greater than it.

// Return an integer denoting the total number of qualified elements in nums.

// Look For Reference In the Book-2 On Pg No 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getK(vector<int>& nums, int k)
{
    if(k==0)    return nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for(int num : nums){
        if(num<nums[nums.size()-k]) ans++;
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 2, 1};
    cout<<getK(arr, 1)<<endl;
    return 0;
}