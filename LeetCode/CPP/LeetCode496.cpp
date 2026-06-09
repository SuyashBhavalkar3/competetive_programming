// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
// If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Look For Reference In the Book On Pg No 38-39-40

#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int, int> map;
    stack<int> monoSt;
    int o = nums2.size();
    for(int i=0;i<o;i++){
        while (!monoSt.empty() && nums2[i]>monoSt.top()){
            map.insert_or_assign(monoSt.top(), nums2[i]);
            monoSt.pop();
        }
        monoSt.push(nums2[i]);
    }
    while(!monoSt.empty()){
        map.insert_or_assign(monoSt.top(), -1);
        monoSt.pop();
    }
    vector<int> ans(nums1.size());
    int m = ans.size();
    for(int i=0;i<m;i++){
        ans[i] = map[nums1[i]];
    }
    return ans;
};

int main(){
    cout<<"Enter Array 1 limit : ";
    int limit1;
    cin>>limit1;
    cout<<"Enter Array 2 limit : ";
    int limit2;
    cin>>limit2;
    vector<int> nums1(limit1);
    cout<<"Enter Elements Of Array 1 : ";
    for(int i=0;i<limit1;i++){
        int val;
        cin>>val;
        nums1[i] = val;
    }
    vector<int> nums2(limit2);
    cout<<"Enter Elements Of Array 2: ";
    for(int i=0;i<limit2;i++){
        int val;
        cin>>val;
        nums2[i] = val;
    }

    vector<int> res = nextGreaterElement(nums1, nums2);

    int n = res.size();
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<res[i];
        if(i!=n-1)
        cout<<", ";
    }
    cout<<"]";
    return 0;

}