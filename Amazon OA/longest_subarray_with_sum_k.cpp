#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int Find_Longest_Subarray(vector<int>& nums, int k){
    unordered_map<int, int> map;
    map[0] = 0;
    int i = 1;
    int sum = 0;
    int maxLength = 0;
    for(int num : nums){
        sum+=num;
        int needed = k - sum;
        if(map.find(needed)!=map.end()){
            maxLength = max(maxLength, i - map[needed]);
        }
        if(map.find(sum)==map.end()){
            map[sum] = i;
        }
        i++;
    }
    return maxLength;
}

int main(){
    vector<int> nums = {0, 5, 2, 7, 1, 9};
    int k = 15;
    int length = Find_Longest_Subarray(nums, k);
    cout<<"The Longest Subaaray with sum k : "<<length<<endl;
    return 0;
}