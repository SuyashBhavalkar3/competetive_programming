#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> intervalsAfterMerge(vector<vector<int>>& intervals){
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    if(intervals.size()<=1){
        return intervals;
    }
    for(int i=0;i<intervals.size();i++){
        if(result.empty()||result.back()[1]<intervals[i][0]){
            result.push_back(intervals[i]);
        }
        else{
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
    }
    return result;
}

int main(){
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = intervalsAfterMerge(intervals);
    for(auto& interval : result){
        cout<<"["<<interval[0]<<", "<<interval[1]<<"] ";
    }
    return 0;
}