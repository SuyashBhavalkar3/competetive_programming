// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students.
// The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student.
// In other words, out of all possible allocations,
// find the arrangement where the student who receives the most pages still has the smallest possible maximum.


// Look For Reference In the Book On Pg No 92-93


#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

bool isPossible(vector<int>& arr, int k, int mid){
    int pages = 0;
    int StudentCnt = 1;
    for(int pagesCnt : arr){
        if (pagesCnt>mid)   return false;
        if(pages + pagesCnt > mid){
            StudentCnt++;
            pages = pagesCnt;
            if(StudentCnt>k)    return false;
        }
        else    pages+=pagesCnt;
    }
    return true;
};

int allocateMin(vector<int>& arr, int k){
    int n = arr.size();
    if(k>n) return -1;
    int result = -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(arr, k, mid)){
            result = mid;
            high = mid-1;
        }
        else    low = mid+1;
    }
    return result;
};

int main(){
    vector<int> arr = {12,34,67,90};
    int k = 2;
    cout<<"Minimum Allocated Maximum Pages Are : "<<allocateMin(arr, k)<<endl;
    return 0;
}