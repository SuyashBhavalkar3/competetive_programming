// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the
// permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the
// permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

// Look For Reference In the Book-2 On Pg No 52-53


#include<iostream>
#include<vector>

using namespace std;

void reverse(int i, int j, vector<int>& nums){
    while(i<j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
};

void next_permutation(vector<int>& nums){
    int n = nums.size();
    int pivot = -1;
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot==-1){
        reverse(0, n-1, nums);
    }
    for(int i=n-1;i>pivot;i--){
        if(nums[i]>nums[pivot]){
            int temp = nums[i];
            nums[i] = nums[pivot];
            nums[pivot] = temp;
            break;
        }
    }
    reverse(pivot+1, n-1, nums);
};

int main(){
    vector<int> nums = {1, 2, 6, 5, 4, 3};
    next_permutation(nums);
    for(int num : nums){
        cout<<num<<" ";
    }
    return 0;
}