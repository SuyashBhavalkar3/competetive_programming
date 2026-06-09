// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.

// Look For Reference In the Book On Pg No 22

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findMajority(vector<int>& nums){
    unordered_map<int, int> freqMap;
    int n = nums.size();
    for(int i=0;i<n;i++){
        freqMap[nums[i]]++;
        if (freqMap[nums[i]]>n/2){
            return nums[i];
        }
    }
    return -1;
};

int main(){
    cout<<"Enter Limit Of Array : ";
    int limit;
    cin>>limit;
    vector<int> arr(limit);
    cout<<"Enter Elements : "<<endl;
    for(int i=0;i<limit;i++){
        int val;
        cin>>val;
        arr[i] = val;
    }
    int res = findMajority(arr);
    if(res!=-1)
    cout<<"Max Element Is : "<<res;
    else
    cout<<"No Majority Element.";
}