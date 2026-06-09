// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Look For Reference In the Book-2 On Pg No 98-99


#include<iostream>
#include<vector>

using namespace std;

vector<int> helper(int n){
    vector<int> res;
    res.push_back(1);
    int ans = 1;
    for(int i = 1; i<n; i++){
        ans = ans*(n-i);
        ans = ans/i;
        res.push_back(ans);
    }
    return res;
};

vector<vector<int>> pascalTriangle(int numRows){
    vector<vector<int>> ans;
    for(int i=1;i<=numRows;i++){
        ans.push_back(helper(i));
    }
    return ans;
};

int main(){
    int numRows = 5;
    vector<vector<int>> ans = pascalTriangle(numRows);
    for(auto& row: ans){
        for(int num:row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
};