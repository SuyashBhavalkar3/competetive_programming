// You are given an integer array height of length n.
// There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Look For Reference In the Book On Pg No 142


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int max_water(vector<int>& water){
    int maxWater = 0;
    int lb = 0;
    int rb = water.size()-1;
    while(lb<rb){
        maxWater = max(maxWater, (rb-lb)*min(water[rb], water[lb]));
        water[lb]>water[rb]?rb--:lb++;
    }
    return maxWater;
}

int main(){
    vector<int> water = {1,8,6,2,5,4,8,3,7};
    cout<<"Container With Max Water Is : "<<max_water(water);
}