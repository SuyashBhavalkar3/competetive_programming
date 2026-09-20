#include<iostream>
#include<vector>

using namespace std;

int majority_element(vector<int>& nums){
    int candidate = 0;
    int balance = 0;
    for(int num : nums){
        if(balance==0){
            candidate = num;
        }
        if(num == candidate){
            balance++;
        }
        else{
            balance--;
        }
    }
    return candidate;
}

int main(){
    vector<int> arr = {2, 2, 2, 3, 3};
    int majority = majority_element(arr);
    cout<<"THe Majority Element Is : "<<majority<<endl;
}