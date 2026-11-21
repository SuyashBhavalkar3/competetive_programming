#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int Count_Subarray_XOR_K(vector<int>& nums, int k){
    int cnt = 0;
    int xr = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for(int num : nums){
        xr = xr^num;
        int needed = xr^k;
        cnt+=map[needed];
        map[xr]++;
    }
    return cnt;
}

int main(){
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    int subarrayCnt = Count_Subarray_XOR_K(nums, k);
    cout<<"The number of subarrays whose xor is equal to k are : "<<subarrayCnt<<endl;
    return 0;
}