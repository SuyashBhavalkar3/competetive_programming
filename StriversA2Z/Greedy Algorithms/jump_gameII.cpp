#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minStepsGame(vector<int>& game){
    int jumps = 0;
    int l = 0, r = 0;
    int farthest = 0;
    while(r<game.size()-1){
        
        for(int i=l;i<=r;i++){
            farthest = max(farthest, i+game[i]);
        }
        l = r+1;
        r = farthest;
        jumps++;
    }
    return jumps;
}    

int main(){
    vector<int> game = {2, 3, 1, 4, 1, 1, 1, 2};
    int minSteps = minStepsGame(game);
    cout<<"The minimum steps needed to complete the game are : "<<minSteps<<endl;
    return 0;
}