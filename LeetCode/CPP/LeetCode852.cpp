// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

// Look For Reference In the Book On Pg No 44-45


#include<iostream>
#include<vector>

using namespace std;

int findPeek(vector<int>& arr){
    int low=0;
    int high=arr.size()-1;
    while(low<high){
        int mid = low + (high-low)/2;
        if(arr[mid]<arr[mid+1]){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int main(){
    vector<int> arr{4, 5, 3, 2, 1};
    int res = findPeek(arr);
    cout<<"Peek Element Of Array Is : "<<arr[res]<<endl;
    return 0;
}