#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

void sort_colors(vector<int>& arr){
    int n = arr.size();
    int left, mid = 0;
    int right = n-1;
    while(mid<right){
        if(arr[mid]==0){
            left++;
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid], arr[right]);
            right--;
        }
        else{
            mid++;
        }
    }
}

int main(){
    vector<int> arr = {2,0,2,1,1,0};
    sort_colors(arr);
    for(int num : arr){
        cout<<num<<" ";
    }
}