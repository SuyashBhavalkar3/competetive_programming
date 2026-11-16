#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

bool CanEat(vector<int>& piles, int mid, int hours){
    int sum = 0;
    for(int num : piles){
        sum+=ceil((double)num/mid);
    }
    return sum<=hours;
}

int Minimum_Banana_Per_Hour(vector<int>& piles, int hrs){
    int n = piles.size();
    int low = 1;
    int high = piles[n-1];
    for(int num : piles){
        if(num>high){
            high = num;
        }
    }
    int ans = 0;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(CanEat(piles, mid, hrs)){
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
    vector<int> piles = {30, 11, 23, 4, 20};
    int hours = 5;
    int minK = Minimum_Banana_Per_Hour(piles, hours);
    cout<<"The Minimum Banans Need To Eat Per Hour : "<<minK<<endl;
    return 0;
}