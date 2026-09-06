#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string longest_common_prefix(vector<string>& str){
    sort(str.begin(), str.end());
    if(str.size()==0){
        return "";
    }
    string first = str[0];
    string last = str[str.size()-1];
    string ans = "";
    int length = min(first.size(), last.size());
    for(int i=0;i<length;i++){
        if(first[i]!=last[i]){
            break;
        }
        ans+=first[i];
    }
    return ans;
}

int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    string lcp = longest_common_prefix(strs);
    cout<<"The Longest Common Prefix Is : "<<lcp<<endl;
    return 0;
}