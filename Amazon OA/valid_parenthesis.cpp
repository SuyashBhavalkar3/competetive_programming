#include<iostream>
#include<vector>

using namespace std;

bool Valid_Parenthesis(string str){
    int min = 0;
    int max = 0;
    for(char ch : str){
        if(ch == '('){
            min++;
            max++;
        }
        else if(ch == ')'){
            min--;
            max--;
        }
        else{
            min--;
            max++;
        }
        if(min<0){
            min=0;
        }
        if(max<0){
            return false;
        }
    }
    return min == 0;
}

int main(){
    string str = "()**(*";
    bool result = Valid_Parenthesis(str);
    cout<<boolalpha;
    cout<<"The Given String Is Valid Parenthesis : "<<result<<endl;
    return 0;
}