#include<iostream>
#include<vector>

using namespace std;

int find_water_trapped(vector<int>& arr){
    int n = arr.size();
    int leftMax = 0, rightMax = 0, total = 0;
    int left = 0, right = n-1;
    while(left<right){
        if(arr[left]<=arr[right]){
            if(leftMax>arr[left])   total+=leftMax-arr[left];
            else    leftMax = arr[left];
            left++;
        }
        else{
            if(rightMax>arr[right])     total+=rightMax-arr[right];
            else    rightMax = arr[right];
            right--;
        }
    }
    return total;
};

int main(){
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trapped_water = find_water_trapped(arr);
    cout<<"The Trapped Rainwater Is : "<<trapped_water<<" Units."<<endl;
    return 0;
}