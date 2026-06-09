// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Look For Reference In the Book-2 On Pg No 91-92


#include<iostream>
#include<vector>

using namespace std;

void recurse(vector<string>& ans, string curr, int open, int close, int total){
    if(curr.size()==2*total){
        ans.push_back(curr);
        return;
    }
    if(open<total){
        recurse(ans, curr+"(", open+1, close, total);
    }
    if(close<open){
        recurse(ans, curr+")", open, close+1, total);
    }
};

vector<string> valid_parenthesis(int n){
    vector<string> ans;
    recurse(ans, "", 0, 0, n);
    return ans;
};

int main(){
    int n = 3;
    vector<string> result = valid_parenthesis(n);
    cout<<"All combinations of "<<n<<" pairs of valid parentheses are: "<<endl;
    for(string s : result){
        cout<<s<<endl;
    }
    return 0;
}