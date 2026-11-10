#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int childrensThatSatisfies(vector<int>& childGreed, vector<int>& cookieSize){
    int satisfiedChildrens = 0;
    sort(childGreed.begin(), childGreed.end());
    sort(cookieSize.begin(), cookieSize.end());
    vector<bool> cookieUsed(cookieSize.size(), false);
    for(int i=0;i<childGreed.size();i++){
        for(int j=0;j<cookieSize.size();j++){
            if(!cookieUsed[j] && childGreed[i]<=cookieSize[j]){
                satisfiedChildrens++;
                cookieUsed[j] = true;
                break;
            }
        }
    }
    return satisfiedChildrens;
}

int main(){
    vector<int> childGreed = {1, 2, 3};
    vector<int> cookieSize = {1, 2, 3};
    int result = childrensThatSatisfies(childGreed, cookieSize);
    cout<<"The Maximum Count Of Childrens That We Can Satisfy Is : "<<result<<endl;
    return 0;
}