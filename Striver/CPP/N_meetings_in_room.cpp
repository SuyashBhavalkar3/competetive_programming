// Given one meeting room and N meetings represented by two arrays, start and end,
// where start[i] represents the start time of the ith meeting and end[i]
// represents the end time of the ith meeting, determine the maximum number of meetings
// that can be accommodated in the meeting room if only one meeting can be held at a time.

// Look For Reference In the Book-3 On Pg No 14-15


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second<b.second;
};


int N_meetings_in_room(vector<int>& start, vector<int>& end){
    int n = start.size();
    if(n==0)    return 0;
    vector<pair<int, int>> meetings;
    for(int i=0;i<n;i++){
        meetings.push_back({start[i], end[i]});
    }
    sort(meetings.begin(), meetings.end(), compare);
    int cnt = 1;
    int lastEnd = meetings[0].second;
    for(int i=1;i<n;i++){
        if(meetings[i].first>=lastEnd){
            cnt++;
            lastEnd = meetings[i].second;
        }
    }
    return cnt;
};

int main(){
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int N_meetings = N_meetings_in_room(start, end);
    cout<<"Number Of Meetings Possible : " <<N_meetings<<endl;
    return 0;
};