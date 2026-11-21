#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long double count_station(vector<int>& cordinates, long double dist){
    int cnt = 0;
    for(int i=1;i<cordinates.size();i++){
        int numberInBetween = (cordinates[i] - cordinates[i-1])/dist;
        if((cordinates[i] - cordinates[i-1])/dist == numberInBetween * dist){
            numberInBetween--;
        }
        cnt+=numberInBetween;
    }
    return cnt;
}

long double find_min_distance(vector<int>& cordinates, int k){
    int n = cordinates.size();
    double low = 0;
    double high = INT_MIN;
    for(int i=1;i<n;i++){
        high = max(high, (double)cordinates[i]-cordinates[i-1]);
    }
    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = low + (high - low)/2.0;
        if(count_station(cordinates, mid)>k){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return high;
}

int main(){
    vector<int> cordinates = {1, 2, 3, 4, 5};
    int k = 4;
    long double mindistance = find_min_distance(cordinates, k);
    cout<<"The minimum maximum distance is : "<<(mindistance)<<endl;
}