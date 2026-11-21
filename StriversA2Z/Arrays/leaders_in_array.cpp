#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leadersInArray(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return nums;
        }
        vector<int> ans;
        int max = nums[n-1];
        ans.push_back(max);
        for(int i=n-2;i>=0;i--){
            if(nums[i]>max){
                ans.push_back(nums[i]);
                max = nums[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    };
};

int main() {
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    Solution solution;
    vector<int> leaders = solution.leadersInArray(nums);

    for (int value : leaders) {
        cout << value << " ";
    }

    return 0;
}
