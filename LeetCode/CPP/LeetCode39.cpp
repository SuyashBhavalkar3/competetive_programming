// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


// Look For Reference In the Book On Pg No 33-34-35


#include<iostream>
#include<vector>
using namespace std;

void backtrack(vector<int>& candidates, int target, int start, vector<int>& comb, vector<vector<int>>& res){
    if(target==0){
        res.push_back(comb);
    }
    if(target<0){
        return;
    }
    int n = candidates.size();
    for(int i=start;i<n;i++){
        comb.push_back(candidates[i]);
        backtrack(candidates, target-candidates[i], i, comb, res);
        comb.pop_back();
    }
};

vector<vector<int>> findCombinations(vector<int>& candidates, int target){
    vector<vector<int>> res;
    vector<int> com;
    backtrack(candidates, target, 0, com, res);
    return res;
}

int main(){
    vector<int> candidates;
    candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> res = findCombinations(candidates, target);
    cout<<"[";
    int m = res.size();
    for(int j=0;j<m;j++){
        int n = res[j].size();
        cout<<"[";
        for(int i =0;i<n;i++){
            cout<<res[j][i];
            if(i!=n-1){
                cout<<", ";
            }
        }
        cout<<"]";

        if(j!=m-1){
        cout<<"], ";
        }
        
    }
    cout<<"]";
    return 0;
}