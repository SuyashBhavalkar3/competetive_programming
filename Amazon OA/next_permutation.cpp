#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    // Rearranges nums into the next lexicographic permutation.
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return;
        }
        int idx = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[idx]){
                int tmp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = tmp;
            }
        }
        reverse(nums.begin()+idx+1, nums.end());
        return;
    }

};

// Driver code
int main() {
    vector<int> nums = {2, 1, 5, 4, 3};

    // instance for class Solution
    Solution sol;

    sol.nextPermutation(nums);

    // Print the array after in-place rearrangement.
    for (int value : nums) {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}