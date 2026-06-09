// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2].
// Each integer appears exactly once except a which appears twice and b which is missing.
// The task is to find the repeating and missing numbers a and b.
// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.


// Look For Reference In the Book On Pg No 28-29

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> findMissingAndRepeating(vector<vector<int>> grid){
    int n = grid.size();
    int maxNum = n*n;
    unordered_map<int, int> map;
    vector<int> temp(2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[grid[i][j]]++;
        }
    }
    for(int k=1;k<=maxNum;k++){
        if (map[k]==0)  temp[0]=k;
        if (map[k]>1)   temp[1]=k;
    }
    return temp;
}

int main(){
    cout<<"Enter Number Of Rows And Columns Of Matrix : ";
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        cout<<"Enter Element Of Row"<<(i+1)<<endl;
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            arr[i][j] = val;
        }
    }
    vector<int> res = findMissingAndRepeating(arr);
    cout<<"Missing Number Is "<<res[0]<<" And Repeating Number Is "<<res[1]<<endl;
}