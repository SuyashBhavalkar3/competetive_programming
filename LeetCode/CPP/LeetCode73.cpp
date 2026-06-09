// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Look For Reference In the Book-2 On Pg No 96-97


#include<iostream>
#include<vector>

using namespace std;

void setMatrixZero(vector<vector<int>>& matrixArr){
    bool firstColZero = false;
    for(auto &row : matrixArr){
        if(row[0]==0){
            firstColZero=true;
        }
        for(int j=1;j<matrixArr[0].size();j++){
            if(row[j]==0){
                row[0] = 0;
                matrixArr[0][j] = 0;
            }
        }
    }
    for(int i=1;i<matrixArr.size();i++){
        for(int j=1;j<matrixArr[0].size();j++){
            if(matrixArr[i][0]==0||matrixArr[0][j]==0){
                matrixArr[i][j] = 0;
            }
        }
    }
    if(matrixArr[0][0]==0){
        for(int i=0;i<matrixArr[0].size();i++){
            matrixArr[0][i] = 0;
        }
    }
    if(firstColZero){
        for(auto &row: matrixArr){
            row[0] = 0;
        }
    }
}

int main(){
    vector<vector<int>> matrixArr = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    setMatrixZero(matrixArr);
    for(const auto &row: matrixArr){
        for(const auto &elem: row){
            cout<<elem<<" ";
        }
        cout<<endl;
    }
    return 0;
}