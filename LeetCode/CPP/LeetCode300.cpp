// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Look For Reference In the Book-2 On Pg No 78-79


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LIS(vector<int>& arr){
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i = 1 ; i<arr.size(); i++){
        if(temp.back()<arr[i]){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int lb = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
            temp[lb] = arr[i];
        }
    }
    return len;
};

int main(){
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout<<"Length of Longest Increasing Subsequence is : "<<LIS(arr)<<endl;
    return 0;
}