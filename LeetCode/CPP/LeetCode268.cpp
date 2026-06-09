#include <iostream>
#include <vector>

using namespace std;

int missing_num(vector<int>& nums){
    int n = nums.size();
    int max_sum = (n*(n+1))/2;
    for(int num : nums){
        max_sum-=num;
    }
    return max_sum;
}

int main(){
    vector<int> arr = {9,7,6,5,4,3,2,1,0};
    cout<<"Missing Number Is : "<<missing_num(arr)<<endl;
    return 0;
}
