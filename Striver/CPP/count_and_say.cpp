#include<iostream>
#include<vector>

using namespace std;

string countAndSay(int n){
    if(n==1){
        return to_string(1);
    }
    string result = "1";
    for(int i=1;i<n;i++){
        int count = 1;
        string ans = "";
        for(int j=1;j<result.size();i++){
            if(result[j]==result[j-1]){
                count++;
            }
            else{
                ans+=to_string(count)+result[j-1];
                count=1;
            }
        }
        ans+=to_string(count)+result.back();
        result = ans;
    }
    return result;
}

int main(){
    int n = 1;
    string result = countAndSay(n);
    cout<<"The Result of count and say of number : "<<n <<" is : "<<result<<endl;
    return 0;
}