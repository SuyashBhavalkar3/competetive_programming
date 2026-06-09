// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
// return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array,
// which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

// Look For Reference In the Book On Pg No 137


#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> next_greater(vector<int>& numbers){
    int n = numbers.size();
    vector<int> result(n, -1);
    stack<int> monost;
    for(int i=0;i<2*n;i++){
        int current = numbers[i%n];
        while(!monost.empty()&&numbers[monost.top()]<current){
            result[monost.top()] = current;
            monost.pop();
        }
        if(i<n){
            monost.push(i);
        }
    }
    return result;
};

int main(){
    vector<int> nums = {1,2,3,4,3};
    for(int num : next_greater(nums)){
        cout<<num<<" ";
    }
    return 0;
}
