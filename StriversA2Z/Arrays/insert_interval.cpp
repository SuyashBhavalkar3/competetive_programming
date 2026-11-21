#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<vector<int>> NewIntervalsAfterInsertion(vector<vector<int>>& intervals, vector<int>& newInterval){
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();
    while(i<n && intervals[i][1]<newInterval[0]){
        result.push_back(intervals[i]);
        i++;
    }
    while(i<n && intervals[i][0]<=newInterval[1]){
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    result.push_back(newInterval);
    while(i<n){
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}

int main(){
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> result = NewIntervalsAfterInsertion(intervals, newInterval);
    for(auto& interval : result){
        cout<<"["<<interval[0]<<", "<<interval[1]<<"]"<<" ";
    }
    return 0;
}