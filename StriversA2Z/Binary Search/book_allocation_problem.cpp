#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<numeric>

using namespace std;

bool Can_Allocate(vector<int>& pages, int students, int mid){
    int students_allocated = 1;
    int pagesAllocated = 0;
    for(int i=0;i<pages.size();i++){
        if(pagesAllocated+pages[i]>mid){
            students_allocated++;
            pagesAllocated = pages[i];
        }
        else{
            pagesAllocated+=pages[i];
        }
    }
    return students_allocated==students;
}

int Find_Minimum_Pages(vector<int>& nums, int m){
    sort(nums.begin(), nums.end());
    int low = nums[0];
    int n = nums.size();
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = 0;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(Can_Allocate(nums, m, mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> pages = {25, 46, 28, 49, 24};
    int students = 4;
    int minimum_pages = Find_Minimum_Pages(pages, students);
    cout<<"The Maximum Number Of Pages That Are Minimised Are : "<<minimum_pages<<endl;
    return 0;
}