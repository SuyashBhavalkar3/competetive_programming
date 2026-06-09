// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.


// Look For Reference In the Book On Pg No 69-70

#include<iostream>
#include<vector>
using namespace std;

int findSingle(vector<int>& nums){
    int result = 0;
    for(int num : nums){
        result^=num;
    }
    return result;
}
int main(){
    vector<int> nums = {2, 2, 3, 3, 4};
    int res = findSingle(nums);
    cout<<"The Number Appearing Only Once Is : "<<res<<endl;
    return 0;
}