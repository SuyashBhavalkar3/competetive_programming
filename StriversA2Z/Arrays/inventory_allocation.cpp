#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<int> getUnfulfilledCustomers(vector<vector<int>>& requests, int totalInventory){
    sort(requests.begin(), requests.end(), 
        [](vector<int>& a, vector<int>& b){
            if(a[2]!=b[2]){
                return a[2]>b[2];
            }
            return a[3]<b[3];
        });
    unordered_set<int> ans;
    for(auto& request :requests){
        ans.insert(request[0]);
    }
    int n = requests.size();
    int i = 0;
    while(i<n && totalInventory>0){
        int j = i;
        while(j<n && requests[i][2] == requests[j][2]){
            j++;
        }
        while(totalInventory>0){
            bool allocated = false;
            for(int k = i; k<j && totalInventory>0; k++){
                if(requests[k][1]>0){
                    ans.erase(requests[k][0]);
                    requests[k][1]--;
                    totalInventory--;
                    allocated = true;
                }
            }
            if(!allocated){
                break;
            }
        }
        i = j;
    }
    vector<int> result(ans.begin(), ans.end());
    sort(result.begin(), result.end());
    return result;
}

int main(){
    vector<vector<int>> requests = {{101, 3, 10, 15},
                                    {102, 2, 8, 20},
                                    {103, 5, 8, 25},
                                    {104, 4, 5, 30}};
    int totalInventory = 8;
    vector<int> result = getUnfulfilledCustomers(requests, totalInventory);
    for(auto& ans : result){
        cout<<ans<<" ";
    }
    return 0;
}