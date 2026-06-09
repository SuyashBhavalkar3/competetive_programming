// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Look For Reference In the Book-3 On Pg No 62-63


#include<iostream>
#include<vector>

using namespace std;

void backtrackHelper(vector<int>& nums, vector<int>& currset, vector<vector<int>>& allset, vector<bool>& used){
    if(currset.size()==nums.size()){
        allset.push_back(currset);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]){
            continue;
        }
        currset.push_back(nums[i]);
        used[i] = true;
        backtrackHelper(nums, currset, allset, used);
        currset.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permutations(vector<int>& nums){
    vector<vector<int>> allsets;
    vector<int> currset;
    vector<bool> used(nums.size(), false);
    backtrackHelper(nums, currset, allsets, used);
    return allsets;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permutations(nums);
    for(vector<int> arr : res){
        for(int num : arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}