#include<iostream>
#include<vector>

using namespace std;

bool canMake(vector<int>& flowers, int bouquets, int flowersNeeded, int mid){
    int cnt = 0;
    int bouquetsMade = 0;
    for(int flower : flowers){
        if(flower<=mid){
            cnt++;
            // cout<<"Flower is : "<<flower<<endl;
            // cout<<"Count is : "<<cnt<<endl;
            if(cnt>=flowersNeeded){
                cnt=0;
                bouquetsMade++;
            }
        }
        else{
            cnt = 0;
        }
    }
    return bouquetsMade>=bouquets;
}

int Minimum_Days_Bouquets(vector<int>& flowers, int bouquets, int flowersNeeded){
    int n = flowers.size();
    int low = 0;
    int high = flowers[n-1];
    for(int flower : flowers){
        if(flower>high){
            high = flower;
        }
    }
    if(bouquets*flowersNeeded>n){
        return -1;
    }
    int ans = 0;
    while(low<=high){
        int mid = low + (high - low)/2;
        // cout<<"Mid is : "<<mid<<endl;
        bool isPossible = canMake(flowers, bouquets, flowersNeeded, mid);
        // cout<<boolalpha<<isPossible<<endl;
        if(isPossible){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> flowers = {7, 7, 7, 12, 7, 7};
    int bouquets = 2;
    int adjacentFlowersNeeded = 3;
    int minimumDays = Minimum_Days_Bouquets(flowers, bouquets, adjacentFlowersNeeded);
    cout<<"The minimum days required to make "<<bouquets<<" bouquets with "<<adjacentFlowersNeeded<<" adjacent flowers needed is : "<<minimumDays<<endl;
    return 0;
}