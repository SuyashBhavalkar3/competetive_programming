#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> setMatrixZeroes(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;
    for(int i=0;i<m;i++){
        if(matrix[0][i]==0){
            firstRowZero = true;
        }
    }
    for(int j=0;j<n;j++){
        if(matrix[j][0]==0){
            firstColZero = true;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][0]==0||matrix[0][j]==0){
                matrix[i][j] = 0;
            }
        }
    }
    if(firstRowZero){
        for(int i=0;i<m;i++){
            matrix[0][i] = 0;
        }
    }
    if(firstColZero){
        for(int i=0;i<n;i++){
            matrix[i][0] = 0;
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{0,1,2,0},
                      {3,4,5,2},
                      {1,3,1,5}};
    vector<vector<int>> result = setMatrixZeroes(matrix);
    for(vector<int> arr : result){
        for(int num : arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}