#include <iostream>
#include <vector>

using namespace std;

void swap_nums(vector<int>& arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void sort_colors(vector<int>& arr){
    int start = 0;
    int end = arr.size()-1;
    int loopIdx = 0;
    while(loopIdx<=end){
        if(arr[loopIdx]==0){
            swap_nums(arr, loopIdx, start);
            loopIdx++;
            start++;
        }
        else if(arr[loopIdx]==2){
            swap_nums(arr, loopIdx, end);
            end--;
        }
        else    loopIdx++;
    }
}

int main(){
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    int n = arr.size()-1;
    sort_colors(arr);
    for(int num : arr){
        cout<<num<<" ";
    }
}