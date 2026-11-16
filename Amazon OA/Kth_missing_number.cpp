#include<iostream>
#include<vector>

using namespace std;

int Find_Kth_Missing(vector<int>& nums, int k){
    int low = 0;
    int n = nums.size();
    int high = n-1;
    while(low<=high){
        int mid = low + ( high - low )/2;
        int missing = nums[mid] - (mid+1);
        if(missing<k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high+1+k;
}

int main(){
    vector<int> nums = {2, 3, 4, 7, 11};
    int k = 5;
    int KthMissing = Find_Kth_Missing(nums, k);
    cout<<"The Kth Missing Posotive Integer Is : "<<KthMissing<<endl;
    return 0;
}