// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Look For Reference In the Book On Pg No 31-32


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> three_some(vector<int>& arr){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1, k=n-1;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum<0)   j++;
            else if(sum>0)  k--;
            else{
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1])  j++;
                while(j<k && arr[k]==arr[k+1])  k--;
            }
        }
    }
    return ans;
};

int main(){
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = three_some(arr);
    for(vector<int> arr : res){
        cout<<"[ ";
        for(int num : arr){
            cout<<num<<" ";
        }
        cout<<"], ";
    }
    return 0;
};