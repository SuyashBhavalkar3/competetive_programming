#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int FindChildCounts(vector<int>& childGreed, vector<int>& cookieSize){
    int cnt = 0;
    sort(childGreed.begin(), childGreed.end());
    sort(cookieSize.begin(), cookieSize.end());
    int i = 0, j = 0;
    int n = childGreed.size(), m = cookieSize.size();
    while(i<n && j<m){
        if(childGreed[i]<=cookieSize[j]){
            cnt++;
            i++;
        }
        j++;
    }
}

int main(){
    vector<int> childGreed = {1, 2, 3};
    vector<int> cookieSize = {1, 2, 3};
    int result = FindChildCounts(childGreed, cookieSize);
    cout<<"The Number Of Childrens We Can Satisfy Is : "<<result<<endl;
    return 0;
}