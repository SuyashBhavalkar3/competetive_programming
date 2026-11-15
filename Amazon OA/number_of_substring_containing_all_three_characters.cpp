#include<iostream>
#include<string>
#include<vector>

using namespace std;

int Substrings_Contaning_All_Three_CharacterS(string str){
    int substrs = 0;
    vector<int> lastSeen(3, -1);
    for(int i = 0; i<str.size();i++){
        lastSeen[str[i]-'a'] = i;
        if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
            substrs+= 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        }
    }
    return substrs;
}

int main(){
    string str = "abcabc";
    int substrings = Substrings_Contaning_All_Three_CharacterS(str);
    cout<<"The Number Of Substrings Containing All Three Characters Are : "<<substrings<<endl;
    return 0;
}