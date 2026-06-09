// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
// To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Look For Reference In the Book On Pg No 67-68

#include<iostream>
#include<vector>

using namespace std;

void MergeInArray(vector<int>& nums1, int m, const vector<int>& nums2, int n){
    int i=m-1;
    int j=n-1;
    int k=m+n-1;
    while(i>=0&&j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--] = nums2[j--];
        }
    }
    while(j>=0){
        nums1[k--] = nums2[j--];
    }
};

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    MergeInArray(nums1, 3, nums2, 3);
    cout<<"[";
    int ns = nums1.size();
    for(int i=0;i<ns;i++){
        cout<<nums1[i];
        if(i<ns-1){
            cout<<", ";
        }
    }
    cout<<"]";
}