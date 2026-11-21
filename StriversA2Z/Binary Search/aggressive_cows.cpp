#include<iostream>
#include<vector>

using namespace std;

bool can_place(vector<int>& stalls, int cows, int mid){
    int totalCows = 1;
    int last = 0;
    for(int i=1;i<stalls.size();i++){
        if(stalls[i] - stalls[last]>=mid){
            totalCows++;
            last = i;
        }
        if(totalCows>=cows){
            return true;
        }
    }
    return totalCows>=cows;
}

int Aggressive_Cows(vector<int>& stalls, int cows){
    int n = stalls.size();
    int low = 1;
    int ans = -1;
    int high = stalls[n-1];
    for(int stall : stalls){
        if(stall>high){
            high = stall;
        }
    }
    while(low<=high){
        int mid = low + (high - low)/2;
        if(can_place(stalls, cows, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> stalls = {0,  3,  4,  7,  10,  9};
    int cows = 4;
    int maximum_minimum_distance = Aggressive_Cows(stalls, cows);
    cout<<"The Agreesive cows ANswers : "<<maximum_minimum_distance<<endl;
    return 0;
}