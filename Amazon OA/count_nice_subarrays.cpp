#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int>& nums, int k){
    if(k<0){
        return 0;
    }
    int cnt = 0;
    int left = 0;
    int odd = 0;
    int right = 0;
    while(right<nums.size()){
        if(nums[right]%2==1){
            odd++;
        }
        while(odd>k){
            if(nums[left]%2==1){
                odd--;
            }
            left++;
        }
        cnt+=right - left + 1;
        right++;
    }
    return cnt;
}

int Nice_Subarrays(vector<int>& nums, int k){
    return helper(nums, k) - helper(nums, k-1);
}

int main(){
    vector<int> arr = {1, 1, 2, 1, 1};
    int k = 3;
    int countOfNiceSubarrays = Nice_Subarrays(arr, k);
    cout<<"The Count Of Nice Subaarays Is : "<<countOfNiceSubarrays<<endl;
    return 0;
}