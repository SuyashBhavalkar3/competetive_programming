#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>

using namespace std;

int maximumPointsWeCanObtain(vector<int>& nums, int k){
    int n = nums.size();
    if(k<0||k>n||n==0){
        return -1;
    }
    if(k==n){
        return accumulate(nums.begin(), nums.end(), 0);
    }
    int lc = 0;
    int rc = 0;
    for(int i = 0 ; i < k ; i++){
        lc+=nums[i];
    }
    int maxPoints = 0;
    int rightIndex = n-1;
    for(int i= k-1; i>=0;i--){
        lc-=nums[i];
        rc+=nums[rightIndex--];
        maxPoints = max(maxPoints, lc+rc);
    }
    return maxPoints;
}

int main(){
    vector<int> nums = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int maxPoints = maximumPointsWeCanObtain(nums, 4);
    cout<<"The Maximum Points We Can Obtain From Cards : "<<maxPoints<<endl;
    return 0;
}