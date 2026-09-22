#include<iostream>
#include<vector>

using namespace std;

void mergeArray(vector<int>& nums, int low, int pivot, int high){
    int l1 = pivot - low + 1;
    int r1 = high - pivot;
    vector<int> l1arr(l1);
    vector<int> r1arr(r1);
    for(int i=0;i<l1;i++){
        l1arr[i] = nums[low+i];
    }
    for(int i=0;i<r1;i++){
        r1arr[i] = nums[pivot+i+1];
    }
    int i=0, j=0, k=low;
    while(i<l1 && j<r1){
        if(l1arr[i]<=r1arr[j]){
            nums[k] = l1arr[i];
            i++;
        }
        else{
            nums[k] = r1arr[j];
            j++;
        }
        k++;
    }
    while(i<l1){
        nums[k++] = l1arr[i++];
    }
    while(j<r1){
        nums[k++] = r1arr[j++];
    }
}

void merge_sort(vector<int>& nums, int low, int high){
    if(low>=high){
        return;
    }
    int pivot = low + (high - low)/2;
    merge_sort(nums, low, pivot);
    merge_sort(nums, pivot+1, high);
    mergeArray(nums, low, pivot, high);
}

int main(){
    vector<int> nums = {38, 27, 43, 3, 9, 82, 10};
    cout<<"Array after merge sort : "<<endl;
    merge_sort(nums, 0, nums.size()-1);
    for(int num : nums){
        cout<<num<<" ";
    }
    return 0;
}