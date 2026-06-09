// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Look For Reference In the Book-2 On Pg No 19


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& TwoDarr){
    vector<vector<int>> result;
    sort(TwoDarr.begin(), TwoDarr.end());
    result.push_back(TwoDarr[0]);
    for(int i=1;i<TwoDarr.size();i++){
        if(TwoDarr[i][0]<=result.back()[1]){
            result.back()[1] = max(result.back()[1], TwoDarr[i][1]);
        }
        else{
            result.push_back(TwoDarr[i]);
        }
    }
    return result;
};

int main(){
    vector<vector<int>> matrix = {
                                    {1, 3},
                                    {2, 6},
                                    {8, 10},
                                    {15, 18}
                                };
    vector<vector<int>> result = mergeIntervals(matrix);
    cout<<"[ ";
    for(int i=0;i<result.size();i++){
        cout<<"["<<result[i][0]<<", "<<result[i][1]<<"]";
        if(i!=result.size()-1){
            cout<<", ";
        }
    }
    cout<<" ]";
    return 0;
}