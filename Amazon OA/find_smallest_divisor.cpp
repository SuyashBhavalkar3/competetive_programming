#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

bool Can_Divide(vector<int>& nums, int threshold, int mid){
    int sum = 0;
    for(int num : nums){
        sum+=ceil((double)num/mid);
        // cout<<"Nums is : "<<num<<endl;
        // cout<<"Mid is : "<<mid<<endl;
        // cout<<"Ceil is : "<<ceil((double)num/mid)<<endl;
    }
    // cout<<"Sum is : "<<sum<<endl;
    // cout<<"Threshold is : "<<threshold<<endl;
    return sum<=threshold;
}

int Find_Smallest_Divisor(vector<int>& nums, int threshold){
    int low = 1;
    int high = nums[nums.size()-1];
    int ans = -1;
    for(int num : nums){
        if(num>high){
            high = num;
        }
    }
    while(low<=high){
        int mid = low + (high - low)/2;
        bool canDivide = Can_Divide(nums, threshold, mid);
        if(canDivide){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
}

int main(){
    vector<int> nums = {44, 22, 33, 11, 1};
    int threshold = 5;
    int smallestDivisor = Find_Smallest_Divisor(nums, threshold);
    cout<<"The Smallest Divisor That Satisfies The Threshold Is : "<<smallestDivisor<<endl;
    return 0;
}