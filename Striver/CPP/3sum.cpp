#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> three_sum(vector<int>& arr){
    vector<vector<int>> triplets;
    int n = arr.size();
    if(n<3){
        return triplets;
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<n-2;i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        int left = i+1;
        int right = n-1;
        while(left<right){
            int sum = arr[i]+arr[left]+arr[right];
            if(sum<0){
                left++;
            }
            else if(sum>0){
                right--;
            }
            else{
                triplets.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;
                while(left<right && arr[left]==arr[left-1]){
                    left++;
                }
                while(left<right && arr[right]==arr[right+1]){
                    right--;
                }
            }
        }
    }
    return triplets;
}

int main(){
    vector<int> arr = {1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = three_sum(arr);
    for(vector<int> arr : triplets){
        for(int num : arr){
            cout<<num<<" ";
        }
    }
    return 0;
}