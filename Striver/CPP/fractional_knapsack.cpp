// You have n items; the i-th item has value val[i] and weight wt[i].

// A knapsack can carry at most capacity units of weight.

// You may take any fraction of an item (i.e. split items).

// Return the maximum total value that can be placed in the knapsack, rounded to exactly 6 decimal places.

// Look For Reference In the Book-3 On Pg No 28-29


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return (double)a.first*b.second>(double)b.first*a.second;
}

double fractional_knapsack(vector<int>& val, vector<int>&  weight, int capacity){
    int n = val.size();
    if(capacity==0 || n == 0){
        return 0;
    }
    vector<pair<int, int>> pairOfValAndWeight(n);
    for(int i=0;i<n;i++){
        pairOfValAndWeight[i] = {val[i], weight[i]};
    }
    sort(pairOfValAndWeight.begin(), pairOfValAndWeight.end(), compare);
    double totalVal = 0;
    for(int i=0;i<n;i++){
        if(pairOfValAndWeight[i].second<=capacity){
            totalVal+=pairOfValAndWeight[i].first;
        }
        else{
            totalVal+=((double)pairOfValAndWeight[i].first/pairOfValAndWeight[i].second)*capacity;
            break;
        }
        capacity-=pairOfValAndWeight[i].second;
    }
    return totalVal;
};

int main(){
    vector<int> val = {60,100,120};
    vector<int> weight = {10,20,30};
    int capacity = 50;
    double value = fractional_knapsack(val, weight, capacity);
    cout<<"Maximum Value That Can Be Occupied Is : "<<value<<endl;
    return 0;
}