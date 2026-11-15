#include<iostream>
#include<vector>

using namespace std;

int Find_FirstOccurence(vector<int>& nums, int x){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid]>=x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid +1;
        }
    }
    return ans;
}

int Find_last(vector<int>& nums, int x){
    int n = nums.size();
    int ans = n;
    int low = 0;
    int high = n-1;
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid]>x){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans-1;
}

vector<int> First_Last_Ocurrence(vector<int>& nums, int x){
    int first = Find_FirstOccurence(nums, x);
    // cout<<"First is : "<<nums[first]<<endl;
    if(nums[first]!=x){
        return {-1, -1};
    }
    int last = Find_last(nums, x);
    return {first, last};
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int x = 8;
    vector<int> firstAndLast = First_Last_Ocurrence(nums, x);
    cout<<"The First And Last Occurence Is At : "<<firstAndLast[0]<<" And "<<firstAndLast[1]<<endl;
    return 0;
}