#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minimum_platforms(vector<int>& arrival, vector<int>& departure){
    int maxPlatforms = 0;
    int cnt = 0;
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int i = 0, j = 0;
    int n = arrival.size();
    while(i<n){
        if(arrival[i]<departure[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, cnt);
    }
    return maxPlatforms;
}

int main(){
    vector<int> arrival =   {900,  940,  950, 1100, 1500, 1800};
    vector<int> deaprture = {920, 1130, 1150, 1300, 1900, 2000};
    int minPlatforms = minimum_platforms(arrival, deaprture);
    cout<<"The minimum number of platforms required are : "<<minPlatforms<<endl;
    return 0;
}