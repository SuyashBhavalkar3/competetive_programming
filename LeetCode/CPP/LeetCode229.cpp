// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Look For Reference In the Book-2 On Pg No 110-111


#include<iostream>
#include<vector>

using namespace std;

vector<int> majority_element(vector<int>& nums){
    int cnt1 = 0, cnt2 = 0;
    int ele1 = 0, ele2 = 0;
    vector<int> ans;
    for(int num : nums){
        if(cnt1==0 && num!=ele2){
            cnt1++;
            ele1 = num;
        }
        else if(cnt2==0 && num!=ele1){
            cnt2++;
            ele2 = num;
        }
        else if(num == ele1){
            cnt1++;
        }
        else if(num == ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    int count1 = 0, count2 = 0;
    for(int num : nums){
        if(num==ele1)   count1++;
        if(num==ele2)   count2++;
    }
    if(count1>nums.size()/3)    ans.push_back(ele1);
    if(count2>nums.size()/3)    ans.push_back(ele2);
    return ans;
};

int main(){
    vector<int> nums = {1,2};
    vector<int> ans = majority_element(nums);
    for(int num : ans){
        cout<<num<<" ";
    }
}