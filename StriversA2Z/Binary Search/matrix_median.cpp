#include<iostream>
#include<vector>

using namespace std;

int Upper_Bound(vector<int>& row, int ub_element){
    int low = 0;
    int n = row.size();
    int high = n-1;
    int ans = 0;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(row[mid]>ub_element){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int Count_Num(vector<vector<int>>& matrix, int n, int m, int mid){
    int count = 0;
    for(int i=0;i<n;i++){
        count+=Upper_Bound(matrix[i], mid);
    }
    return count;
}

int Find_Matrix_Median(vector<vector<int>>& matrix){
    int low = INT_MAX;
    int high = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n-1]);
    }
    int required = (n*m)/2;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(Count_Num(matrix, n, m, mid)<=required){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    vector<vector<int>> matrix = {{1, 5, 7, 9 ,11}, 
                                  {2, 3, 4, 5, 10},
                                  {9, 10, 12, 14, 16}};
    int matrix_median = Find_Matrix_Median(matrix);
    cout<<"THe Matrix Median Is : "<<matrix_median<<endl;
    return 0;
}