#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map> 

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    stack<int> st;
    unordered_map<int, int> map;
    int n = nums2.size();
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
        }
        if(st.empty()){
            map[nums2[i]] = -1;
        }
        else{
            map[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }
    vector<int> res;
    for(int num : nums1){
        res.push_back(map[num]);
    }
    return res;
}

int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> res = nextGreaterElement(nums1, nums2);
    cout<<"[";
    for(int num : res){
        cout<<num<<" ";
    }
    cout<<"]";
    return 0;
}