// There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

// You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

// Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets.
// If a person does not have any tickets left to buy, the person will leave the line.

// Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

// Look For Reference In the Book On Pg No 96-97

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int timeRequired(vector<int>& tickets, int k){
    int time_req = 0;
    queue<int> que;
    int n = tickets.size();
    for(int i=0;i<n;i++)   que.push(i);
    while(true){
        int index = que.front();
        que.pop();
        time_req++;
        tickets[index]--;
        if(index==k&&tickets[index]==0) break;
        if(tickets[index]>0)    que.push(index);
    }
    return time_req;
}

int main(){
    vector<int> tickets = {2,3,2};
    int k = 2;
    int res = timeRequired(tickets, k);
    cout<<"Time Required In Queue Is : "<<res<<endl;
    return 0;
}