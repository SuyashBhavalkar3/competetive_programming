#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

bool canEat(vector<int>& piles, int speed, int hours){
    int hrs = 0;
    for(int pile : piles){
        hrs+= (pile+speed-1)/speed;
        if(hrs>hours){
            return false;
        }
    }
    return hrs<=hours;
}

int minBananasToEat(vector<int>& piles, int hours){
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    while(left<=right){
        int mid = left + (right - left)/2;
        if(canEat(piles, mid, hours)){
            left = mid - 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

int main(){
    vector<int> piles = {30, 11, 23, 4, 20};
    int minBananas = minBananasToEat(piles, 5);
    cout << "The Minimum Bananas To Eat To End Up all piles in given hours : "<<minBananas;
    return 0;
}