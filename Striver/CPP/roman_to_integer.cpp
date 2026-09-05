#include<iostream>
#include<unordered_map>

using namespace std;

int RomanToInt(string str){
    int res = 0;
    unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int n = str.size();
    res+=roman[str[n-1]];
    for(int i=n-2;i>=0;i--){
        if(roman[str[i]]<roman[str[i+1]]){
            res-=roman[str[i]];
        }
        else{
            res+=roman[str[i]];
        }
    }
    return res;
}

int main(){
    string str = "MCMXCIV";
    int integer_INT = RomanToInt(str);
    cout<<"The Roman number After Converting To Integer Is : "<<integer_INT<<endl;
}