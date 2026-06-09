// Given the arrival and departure times of all trains reaching a particular railway station,
// determine the minimum number of platforms required so that no train is kept waiting.
// Consider all trains arrive and depart on the same day.

// In any particular instance, the same platform cannot be used for both the departure of
// one train and the arrival of another train, necessitating the use of different platforms in such cases.

// Look For Reference In the Book-3 On Pg No 16-17


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int min_plarforms_required(vector<int>& arrival, vector<int>& departure){
    int n = arrival.size();
    if(n==0)    return 0;
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int maxCnt = 0;
    int cnt = 0;
    int i = 0, j = 0;
    while(i<n && j<n){
        if(arrival[i]<=departure[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
};

int main(){
    vector<int> a = {900, 940,  950,  1100, 1500, 1800};
    vector<int> b = {910, 1200, 1120, 1130, 1900, 2000};
    int platforms = min_plarforms_required(a, b);
    cout<<"The Minimum Platforms Required Are : "<<platforms<<endl;
    return 0;
}