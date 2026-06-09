// Given two sorted arrays nums1 and nums2 of size m and n respectively,
// return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Look For Reference In the Book-2 On Pg No 5


#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>

using namespace std;

double getMedianOfTwoSortedArray(vector<int>& nums1, vector<int>& nums2){
    int X = nums1.size();
    int Y = nums2.size();
    if(X>Y){
        return getMedianOfTwoSortedArray(nums2, nums1);
    }
    int low = 0;
    int high = X;
    while(low<=high){
        int partitionX = low + (high-low)/2;
        int partitionY = ((X+Y+1)/2) - partitionX;
        int maxLeftX = (partitionX==0)? INT_MIN : nums1[partitionX-1];
        int maxLeftY = (partitionY==0)? INT_MIN : nums2[partitionY-1];
        int minRightX = (partitionX==X)? INT_MAX : nums1[partitionX];
        int minRightY = (partitionY==Y)? INT_MAX : nums2[partitionY];
        if((maxLeftX<=minRightY) && (maxLeftY<=minRightX)){
            if((X+Y)%2==0){
                return static_cast<double>((max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2);
            }
            else{
                return static_cast<double>(max(maxLeftX, maxLeftY));
            }
        }
        else if(maxLeftX>minRightY){
            high = partitionX-1;
        }
        else{
            low = partitionX+1;
        }
    }
    return 0.0;
}

int main(){
    vector<int> arr1 = {1, 3, 8, 9};
    vector<int> arr2 = {7, 11, 18, 19, 21};
    double median = getMedianOfTwoSortedArray(arr1, arr2);
    cout<<"Median Of Two Sorted Array Is : "<<median<<endl;
    return 0;
}