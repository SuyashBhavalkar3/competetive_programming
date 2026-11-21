#include <vector>
#include <iostream>
using namespace std;

bool comparator(vector<int>& first, vector<int>& second){
    return first[2]>second[2];
}

vector<int> jobScheduling(vector<vector<int>>& jobs){
    sort(jobs.begin(), jobs.end(), comparator);
    int maxDeadline = -1;
    for(auto job : jobs){
        if(job[1]>maxDeadline){
            maxDeadline = job[1];
        }
    }
    int profit = 0;
    int jobsDone = 0;
    vector<int> slots(maxDeadline + 1, -1);
    for (const auto& job : jobs) {
        for (int j = job[1]; j >= 1; j--) {
            if (slots[j] == -1) {
                slots[j] = job[0];
                jobsDone++;
                profit += job[2];
                break;
            }
        }
    }
    return {jobsDone, profit};
}

int main() {
    vector<vector<int>> jobs= {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    vector<int> result = jobScheduling(jobs);
    cout << result[0] << ' ' << result[1] << '\n';
    return 0;
}