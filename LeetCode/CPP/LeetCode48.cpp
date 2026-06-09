// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

// Look For Reference In the Book-2 On Pg No 101
 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void rotateMat(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j = i+1;j<matrix[0].size();j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(auto& row : matrix){
        reverse(row.begin(), row.end());
    }
}

int main(){
    vector<vector<int>> matrix = {
                {1,2,3},
                {4,5,6},
                {7,8,9}};
    cout<<"Original Matrix : "<<endl;
    for(auto& row : matrix){
        for(int num : row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    rotateMat(matrix);
    cout<<"Rotated Matrix : "<<endl;
    for(auto& row : matrix){
        for(int num : row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}