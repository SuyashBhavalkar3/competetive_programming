#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool helper(int index, int sum, int N, vector<int>& nums,  int target){
    if(sum==target){
        return true;
    }
    if(index==N){
        return false;
    }
    return (helper(index+1, sum+nums[index], N, nums, target) || helper(index+1, sum, N, nums, target));
}

bool subset_sum(vector<int>& nums, int target){
    return helper(0, 0, nums.size(), nums, target);
}

int main(){
    vector<int> nums = {1, 2, 7, 3};
    int target = 16;
    bool has = subset_sum(nums, target);
    cout<<boolalpha;
    cout<<"Subset Sum Can Form Target : "<<has<<endl;
}