#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int FindCountNonOverlappingInterval(vector<vector<int>>& intervals){
    int cnt = 0;
    sort(intervals.begin(), intervals.end(),
        [](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        }
    );
    int minLastIndex = intervals[0][1];
    for(int i = 1; i < intervals.size() ; i++){
        if(intervals[i][0]<minLastIndex){
            cnt++;
        }
        else{
            minLastIndex = intervals[i][1];
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> intervals= {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result = FindCountNonOverlappingInterval(intervals);
    cout<<"The Count Of Non Overlapping Intervals Is : "<<result<<endl;
    return 0;
}