#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findUpperBound(int mid, vector<int>& row){
    int cnt = 0;
    for(int i=0;i<row.size();i++){
        if(row[i]>mid){
            return cnt;
        }
        cnt++;
    }
    return cnt;
}

int findSmallers(int mid, vector<vector<int>>& matrix){
    int cnt = 0;
    for(int i = 0; i<matrix.size(); i++){
        cnt+=findUpperBound(mid, matrix[i]);
    }
    return cnt;
}

int findMedianMatrix(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int req = (n*m)/2;
    int low = INT_MAX;
    int high = INT_MIN;
    for(int i=0;i<n;i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }
    while(low<=high){
        int mid = low + ((high-low)/2);
        int smallers = findSmallers(mid, matrix);
        if(smallers<=req){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main(){
    vector<vector<int>> matrix = {{1, 5, 7, 9, 11},
                                  {2, 3, 4, 5, 10},
                                  {9, 10, 12, 14, 16}};
    int median = findMedianMatrix(matrix);
    cout<<"The Median Of The Matrix Is : "<<median<<endl;
    return 0;
}