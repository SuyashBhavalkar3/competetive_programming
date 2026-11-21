#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int fruits_into_basket(vector<int>& trees){
    int maxFruits = 0;
    int n = trees.size();
    unordered_map<int, int> map;
    int left = 0;
    int right = 0;
    while(right<n){
        map[trees[right]]++;
        // cout<<"Map Size is : "<<map.size()<<endl;
        if(map.size()>2){
            map[trees[left]]--;
            // cout<<"Reduced : "<<map[trees[left]]<<endl;
            if(map[trees[left]]==0){
                map.erase(trees[left]);
            }
            left++;
        }
        if(map.size()<=2){
            // cout<<"Left To Rights Fruits Are : "<<endl;
            // for(int i=left;i<=right;i++){
            //     cout<<trees[i]<<", ";
            // }
            // cout<<endl;
            maxFruits = max(maxFruits, right - left + 1);
        }
        right++;
    }
    return maxFruits;
}

int main(){
    vector<int> trees = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    int maxFruits = fruits_into_basket(trees);
    cout<<"The Maximum Fruits We Can Collect From Two Trees Are : "<<maxFruits<<endl;
    return 0;
}