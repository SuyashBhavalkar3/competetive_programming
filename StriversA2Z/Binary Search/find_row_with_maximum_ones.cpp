#include<iostream>
#include<vector>

using namespace std;

int Find_Maximum_Ones_Row(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int columns = matrix[0].size();
    int row = 0;
    int column = columns-1;
    int ans = 0;
    while(row<rows && column>=0){
        if(matrix[row][column]==1){
            ans = row;
            column--;
        }
        else{
            row++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1},
                                  {0, 0, 1},
                                  {0, 0, 0}};
    int row = Find_Maximum_Ones_Row(matrix);
    cout<<"The Row With Maximum Number Of Ones Is : "<<row+1<<endl;
    return 0;
}