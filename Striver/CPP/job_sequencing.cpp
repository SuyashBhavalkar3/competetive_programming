// Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline ,
// Jobs[i][2] represents Profit associated with that job.
// Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.

// The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.

// Look For Reference In the Book-3 On Pg No 26-27


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[2]>b[2];
}

pair<int, int> maximum_profit(vector<vector<int>>& jobs){
    int n = jobs.size();
    if(n==0)    return make_pair(-1, -1);
    sort(jobs.begin(), jobs.end(), compare);
    int maxDeadline = -1;
    for(int i=0;i<n;i++){
        int deadline = jobs[i][1];
        maxDeadline = max(deadline, maxDeadline);
    }
    vector<int> slots(maxDeadline+1, -1);
    int jobCnt = 0;
    int profit = 0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i][1];j>0;j--){
            if(slots[j]==-1){
                slots[j] = i;
                jobCnt++;
                profit+=jobs[i][2];
                break;
            }
        }
    }
    return make_pair(jobCnt, profit);
};

int main(){
    vector<vector<int>> jobs = {{1, 2, 100},
                                {2, 1, 19}, 
                                {3, 2, 27}, 
                                {4, 1, 25}, 
                                {5, 1, 15}};
    pair<int, int> job_and_profit = maximum_profit(jobs);
    cout<<"The Pair Of Job : Profit At Most Is -> "<<job_and_profit.first<<" : "<<job_and_profit.second<<endl;
    return 0;
};