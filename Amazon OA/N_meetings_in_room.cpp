#include <iostream>
#include <utility>
#include <vector>

using namespace std ;

int maxMeetings(vector<int>& start, vector<int> end){
    vector<pair<int, int>> meetings;
    for(int i=0;i<start.size();i++){
        meetings.push_back({end[i], start[i]});
    }
    sort(meetings.begin(), meetings.end());
    int maxMeetings = 0;
    int lastEndTime = -1;
    for(auto meeting : meetings){
        int currentStart = meeting.second;
        int currentEnd = meeting.first;
        if(currentStart>lastEndTime){
            maxMeetings++;
            lastEndTime = currentEnd;
        }
    }
    return maxMeetings;
}

int main() {
    // Driver code starts
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
 
    cout <<maxMeetings(start, end);
 
    return 0;
}