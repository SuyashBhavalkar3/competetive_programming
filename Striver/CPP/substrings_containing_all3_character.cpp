#include<iostream>
#include<vector>

using namespace std;

int substring_contaning_allCharacters(string str){
    int n = str.size();
    vector<int> frequency(3, 0);
    if(n<3){
        return 0;
    }
    int left = 0;
    int count = 0;
    for (int i=0;i<n;i++){
        frequency[str[i]-'a']++;
        while(frequency[0]>0 &&
              frequency[1]>0 &&
              frequency[2]>0){
                count+=n-i;
                frequency[str[left]-'a']--;
                left++;
        }   
    }
    return count;
}

int main(){
    string str = "abcabc";
    int n = substring_contaning_allCharacters(str);
    cout<<"The Number Of Substrings Contaning All 3 Characters Are : "<< n<<endl;
    return 0;
}