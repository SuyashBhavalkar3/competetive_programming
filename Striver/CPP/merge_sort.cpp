#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& arr, int low, int pivot, int high){
    int lengthOfLeftSubArray = pivot - low + 1;
    int lengthOfRightSubArray = high - pivot;
    vector<int> leftSubArray(lengthOfLeftSubArray), rightSubArray(lengthOfRightSubArray);
    for(int i=0;i<lengthOfLeftSubArray;i++){
        leftSubArray[i] = arr[low+i];
    }
    for(int i=0;i<lengthOfRightSubArray;i++){
        rightSubArray[i] = arr[pivot+i+1];
    }
    int i = 0, j = 0, k = low;
    while(i<lengthOfLeftSubArray && j<lengthOfRightSubArray){
        if(leftSubArray[i]<=rightSubArray[j]){
            arr[k++] = leftSubArray[i++];
        }
        else{
            arr[k++] = rightSubArray[j++];
        }
    }
    while(i<lengthOfLeftSubArray){
        arr[k++] = leftSubArray[i++];
    }
    while(j<lengthOfRightSubArray){
        arr[k++] = rightSubArray[j++];
    }
};

void mergeSort(vector<int>& arr, int low, int high){
    if(low>=high)   return;
    int pivot = low + (high-low)/2;
    mergeSort(arr, low, pivot);
    mergeSort(arr, pivot+1, high);
    merge(arr, low, pivot, high);
};

int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();
    mergeSort(arr, 0, n-1);
    cout<<"Sorted array after merge sort: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}