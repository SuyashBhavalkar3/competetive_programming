// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

// Look For Reference In the Book-2 On Pg No 106


#include<iostream>
#include<vector>

using namespace std;

int duplicate_number(vector<int>& nums){
    int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow!=fast);
    fast = nums[0];
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
};

int main(){
    vector<int> nums = {1,3,4,2,2};
    cout<<"Duplicate number is: "<<duplicate_number(nums)<<endl;
    return 0;
}