// Given two sorted arrays nums1 and nums2 of size m and n respectively,
// return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Look For Reference In the Book-2 On Pg No 5


#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

double findMedianTwoSortedArray(vector<int>& nums1, vector<int>& nums2){
    if(nums1.size()>nums2.size()){
        return findMedianTwoSortedArray(nums2, nums1);
    }

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low = 0;
    int high = n1;

    while(low<=high){
        int cut1 = low + (high - low)/2;
        int cut2 = (n1 + n2 + 1)/2 - cut1;

        int l1, l2, r1, r2;
        if(cut1==0)
            l1 = INT_MIN;
        else
            l1 = nums1[cut1-1];
        if(cut1==n1)
            r1 = INT_MAX;
        else
            r1 = nums1[cut1];
        if(cut2==0)
            l2 = INT_MIN;
        else    
            l2 = nums2[cut2-1];
        if(cut2==n2)
            r2 = INT_MAX;
        else
            r2 = nums2[cut2];
        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2==0)
                return (max(l1,l2) +  min(r1, r2))/2.0;
            else
                return max(l1, l2);
        }
        if(l1>r2)
            high = cut1-1;
        else   
            low = cut1+1;
    }
    return 0.0;
}

int main(){
    vector<int> arr1 = {1, 3, 8, 9};
    vector<int> arr2 = {7, 11, 18, 19, 21};
    double result = findMedianTwoSortedArray(arr1, arr2);
    cout<<"The Median Of Two Sorted Arrays Is : "<<result<<endl;
}