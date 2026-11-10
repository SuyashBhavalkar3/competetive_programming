#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool canReachEnd(vector<int>& jump){
    int maxIndex = 0;
    for(int i=0;i<jump.size();i++){
        if(i>maxIndex){
            return false;
        }
        maxIndex = max(maxIndex, i+jump[i]);
    }
    return true;
}

int main(){
    vector<int> jump = {2, 3, 1, 1, 4};
    bool result = canReachEnd(jump);
    cout<<boolalpha;
    cout<<"We can reach end starting from the initial stage : "<<result<<endl;
    return 0;
}