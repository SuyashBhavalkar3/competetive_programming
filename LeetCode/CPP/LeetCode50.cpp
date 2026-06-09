// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Look For Reference In the Book On Pg No 125


#include<iostream>
#include<vector>

using namespace std;

double powHelper(double x, long n){
    if(n==0)    return 1;
    if(n==1)    return x;
    double half = powHelper(x, n/2);
    if(n%2==0)  return half*half;
    return half*half*x;
}

double myPow(double x, long n){
    if(n==0)    return 1;
    if(n<0){
        n=-n;
        x=1/x;
    }
    return powHelper(x, n);
};

int main(){
    double x = 2;
    long pow = 10;
    cout<<"The Power of "<<x<<" raise to "<<pow<<" Is : "<<myPow(x,pow)<<endl;
};