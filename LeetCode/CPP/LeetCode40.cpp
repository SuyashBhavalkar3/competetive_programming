// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Look For Reference In the Book On Pg No 61-62-63

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void backtrack(vector<int> candidates, int target, int start, vector<int>& temp, vector<vector<int>>& res, int n){
    if(target == 0){
        res.push_back(temp);
    }
    if(target < 0)  return;
    for(int i=start;i<n;i++){
        if(i>start && (candidates[i] == candidates[i-1])) continue;
        if(candidates[i]>target)    break;
        temp.push_back(candidates[i]);
        backtrack(candidates, target-candidates[i], i+1, temp, res, n);
        temp.pop_back();
    }
};

vector<vector<int>> findCombinations(vector<int> candidates, int target){
    sort(candidates.begin(), candidates.end());
    int n = candidates.size();
    vector<vector<int>> res;
    vector<int> temp;
    backtrack(candidates, target, 0, temp, res, n);
    return res;
};

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = findCombinations(candidates, target);
    cout<<"[";
    for(auto& temp : result){
        cout<<"[";
        for(int num : temp){
            cout<<num<<" ";
        }
        cout<<"]";
    }
    cout<<"]";
}