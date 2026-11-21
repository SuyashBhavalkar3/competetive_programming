#include <iostream>
#include <vector>

using namespace std;

vector<int> Generated_Row(int row){
    vector<int> nRow;
    int ans = 1;
    nRow.push_back(ans);
    for(int i = 1; i<row;i++){
        ans = ans * (row - i);
        ans = ans/i;
        nRow.push_back(ans);
    }
    return nRow;
}

vector<vector<int>> Pascal_Triangle(int n){
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++){
        ans.push_back(Generated_Row(i));
    }
    return ans;
}

int main(){
    int n = 8;
    vector<vector<int>> ans = Pascal_Triangle(n);
    for(auto arr : ans){
        for(int num : arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}