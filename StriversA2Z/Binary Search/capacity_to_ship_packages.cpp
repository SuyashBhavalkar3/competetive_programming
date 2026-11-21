#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

bool Can_Ship(vector<int>& weights, int days, int mid){
    int daysTaken = 1;
    int i = 0;
    int n = weights.size();
    int capacity = 0;
    // cout<<"Mid is : "<<mid<<endl;
    while(i<n){
        if (weights[i] > mid) {
            return false;
        }
        if(capacity+weights[i]>mid){
            // cout<<"If block in while"<<endl;
            capacity = weights[i];
            daysTaken++;
            
        }
        else{
            capacity+=weights[i];
            // cout<<"Capacity is : "<<capacity<<endl;
            
        }
        i++;
    }
    // cout<<"Days taken : "<< daysTaken<< " and days are : "<<days<<endl;
    return daysTaken<=days;
}

int Find_Min_capacity(vector<int>& weights, int days){
    int n = weights.size();
    int low = 1;
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = 0;
    while(low<=high){
        int mid = low + (high - low)/2;
        // cout<<"Low mid and high passing are : "<< low<<" "<<mid<<" "<<high<<endl;
        bool canShip = Can_Ship(weights, days, mid);
        if(canShip){
            ans = mid;
            high = mid - 1;
            // cout<<"mid reduced"<<endl;
        }
        else{
            low = mid + 1;
            // cout<<"mid increased"<<endl;
        }
    }
    return ans;
}

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    int minCapacity = Find_Min_capacity(weights, days);
    cout<<"The Minimum Capacity Needed TO Ship In Given Days : "<<minCapacity<<endl;
    return 0;
}