// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Look For Reference In the Book-3 On Pg No 60-61


#include<iostream>
#include<vector>
using namespace std;

string get_permutation(int n, int k){
    int factorial = 1;
    vector<int> numbers;
    for(int i=1;i<n;i++){
        numbers.push_back(i);
        factorial = factorial*i;
    }
    numbers.push_back(n);
    string res = "";
    k = k-1;
    while(true){
        res+=to_string(numbers[k/factorial]);
        numbers.erase(numbers.begin() + k/factorial);
        if(numbers.size()==0){
            break;
        }
        k = k%factorial;
        factorial = factorial/numbers.size();
    }
    return res;
}

int main(){
    int n = 4;
    int k = 9;
    string res = get_permutation(n, k);
    cout<<"The "<<k<<"th Permutation Is : "<<res<<endl;
}