// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

// Look For Reference In the Book On Pg No 102-103


#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string str, int start, int end){
    while(start<end){
        if(str[start]!=str[end])    return false;
        start++;
        end--;
    }
    return true;
}

void findPartitions(int start, string str, vector<string>& partition, vector<vector<string>>& allPartition, int n){
    if(start == n){
        allPartition.push_back(partition);
        return;
    }
    for(int end=start;end<n;end++){
        if(isPalindrome(str, start, end)){
            partition.push_back(str.substr(start, end-start+1));
            findPartitions(end+1, str, partition, allPartition, n);
            partition.pop_back();
        }
    }
}

vector<vector<string>> findAllPartition(string str){
    vector<vector<string>> allPartitions;
    vector<string> partition;
    int n = str.size();
    findPartitions(0, str, partition, allPartitions, n);
    return allPartitions;
}

int main(){
    string str = "aab";
    vector<vector<string>> res = findAllPartition(str);
    cout<<"[";
    for(auto &part : res){
        cout<<"[";
        for(string pal : part){
            cout<<"'"<<pal<<"'";
        }
        cout<<"]";
    }
    cout<<"]";
    return 0;
}