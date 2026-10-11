#include<iostream>
#include<vector>

using namespace std;

int trapping_rainwater(vector<int>& nums){
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    int total = 0;
    while(left<=right){
        if(nums[left]<=nums[right]){
            if(nums[left]<leftMax){
                total+=leftMax - nums[left];
            }
            else{
                leftMax = nums[left];
            }
            left++;
        }
        else{
            if(nums[right]<rightMax){
                total+=rightMax - nums[right];
            }
            else{
                rightMax = nums[right];
            }
            right--;
        }
    }
    return total;
}

int main(){
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int Maxunit = trapping_rainwater(nums);
    cout<<"The Maximum Water We Can Trap Is : "<<Maxunit<<endl;
    return 0;
}