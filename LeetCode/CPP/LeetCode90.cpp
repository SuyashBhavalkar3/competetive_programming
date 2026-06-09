#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void recurseAndBacktrack(int idx, vector<vector<int>>& allsets, vector<int>& currentset, vector<int>& nums){
    allsets.push_back(currentset);
    for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i]==nums[i-1]){
            continue;
        }
        currentset.push_back(nums[i]);
        recurseAndBacktrack(i+1, allsets, currentset, nums);
        currentset.pop_back();
    }
}

vector<vector<int>> findSubsets(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> allsets;
    vector<int> currentSet;
    recurseAndBacktrack(0, allsets, currentSet, nums);
    return allsets;
}

int main(){
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> subsets = findSubsets(nums);
    for(vector<int> subset : subsets){
        cout<<"[ ";
        for(int num : subset){
            cout<<num<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}