#include <bits/stdc++.h>
using namespace std;

vector<int> getUnfulfilledCustomers(
    vector<vector<int>> requests,
    int totalInventory
) {
    sort(requests.begin(), requests.end(),
         [](const vector<int>& a, const vector<int>& b) {
             if (a[2] != b[2])
                 return a[2] > b[2];

             return a[3] < b[3];
         });

    unordered_set<int> received;

    int n = requests.size();
    int i = 0;

    while (i < n && totalInventory > 0) {
        int j = i;

        while (j < n && requests[j][2] == requests[i][2]) {
            j++;
        }

        while (totalInventory > 0) {
            bool allocated = false;

            for (int k = i; k < j && totalInventory > 0; k++) {
                if (requests[k][1] > 0) {
                    received.insert(requests[k][0]);

                    requests[k][1]--;
                    totalInventory--;

                    allocated = true;
                }
            }

            if (!allocated)
                break;
        }

        i = j;
    }

    set<int> ans;

    for (auto &req : requests) {
        if (received.find(req[0]) == received.end()) {
            ans.insert(req[0]);
        }
    }

    return vector<int>(ans.begin(), ans.end());
}

int main() {
    vector<vector<int>> requests = {
        {101, 2, 50, 1},
        {102, 3, 50, 2},
        {103, 2, 40, 3},
        {104, 1, 30, 4}
    };

    int totalInventory = 3;

    vector<int> result =
        getUnfulfilledCustomers(requests, totalInventory);

    for (int id : result) {
        cout << id << " ";
    }

    return 0;
}