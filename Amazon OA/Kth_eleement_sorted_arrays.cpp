#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int Find_Kth_Element_Sorted_Array(vector<int>& arr1, vector<int>& arr2, int k){
    if(arr1.size()>arr2.size()){
        return Find_Kth_Element_Sorted_Array(arr2, arr1, k);
    }
    int n = arr1.size();
    int m = arr2.size();
    int low = max(k-n, 0);
    int high = min(k, n);
    while(low<=high){
        int cut1 = low + (high - low)/2;
        int cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];
        if(l1<=r2 && l2<=r1){
            return max(l1, l2);
        }
        else if(l1>r2){
            high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;
    int KthElement = Find_Kth_Element_Sorted_Array(arr1, arr2, k);
    cout<<"The Kth Element Of The 2 Sorted Arrays Are : "<<KthElement<<endl;
    return 0;
}