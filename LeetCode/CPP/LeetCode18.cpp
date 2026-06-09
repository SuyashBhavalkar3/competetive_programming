// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Look For Reference In the Book-2 On Pg No 50-51

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> four_sum(vector<int>& arr, int target){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            int k = j+1, l = n-1;
            while(k<l){
                int sum = arr[i]+arr[j]+arr[k]+arr[l];
                if(sum<target)   k++;
                else if(sum>target)  l--;
                else{
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])  k++;
                    while(k<l && arr[l]==arr[l+1])  l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = four_sum(arr, target);
    for(vector<int> arr : res){
        cout<<"[ ";
        for(int num : arr){
            cout<<num<<" ";
        }
        cout<<"] ";
    }
    return 0;
}