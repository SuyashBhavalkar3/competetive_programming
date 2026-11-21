#include<iostream>
#include<vector>

using namespace std;

vector<int> findUnion(vector<int>& nums1, vector<int> nums2){
    int n = nums1.size();
    int m = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> unionResult;
    while(i<n && j<m){
        int currValue;
        if(nums1[i]<nums2[j]){
            currValue = nums1[i];
            i++;
        }
        else if(nums2[j]<nums1[i]){
            currValue = nums2[j];
            j++;
        }
        else{
            currValue = nums1[i];
            i++;
            j++;
        }
        if(unionResult.empty()||unionResult.back()!=currValue){
            unionResult.push_back(currValue);
        }
    }
    while (i < n) {
        if (unionResult.empty() ||
            unionResult.back() != nums1[i]) {
            unionResult.push_back(nums1[i]);
        }
        i++;
    }
    while (j < m) {
        if (unionResult.empty() ||
            unionResult.back() != nums2[j]) {
            unionResult.push_back(nums2[j]);
        }
        j++;
    }
    return unionResult;
}

int main() {
  vector<int> nums1 = {1, 1, 2, 3, 4};
  vector<int> nums2 = {2, 3, 5, 6};
  vector<int> answer = findUnion(nums1, nums2);
  for (int value : answer) {
    cout << value << " ";
  }
  return 0;
}