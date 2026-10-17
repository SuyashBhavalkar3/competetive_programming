#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> find_subsets(vector<int>& nums){
    vector<vector<int>> allsets;
    int n = nums.size();
    int subsets = 1 << n;
    for(int i = 0; i < subsets ; i++){
        vector<int> sub;
        for(int j = 0; j < n; j++){
            if (i & (1<<j)){
                sub.push_back(nums[j]);
            }
        }
        allsets.push_back(sub);
    }
    return allsets;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> allsets = find_subsets(nums);
    for(vector<int> subset : allsets){
        cout<<"[";
        for(int num : subset){
            cout<<num<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<allsets.size()<<" : Is the Size Of Subsets."<<endl;
    return 0;
}