#include<iostream>
#include<vector>

using namespace std;

double Find_Answer(double mid, int n){
    double ans = 1;
    for(int i = 1;i<=n;i++){
        ans*=mid;
    }
    return ans;
}

double Nth_Root(int number, int n){
    double low = 1;
    double high = number;
    double eps = 1e-6;
    while((high - low) > eps){
        double mid = low + (high - low)/2;
        double answer = Find_Answer(mid, n);
        if(answer<number){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int main(){
    int number = 27;
    int n = 3;
    double result = Nth_Root(number, n);
    cout<<"The Nth Root Of A Number Is : "<<result<<endl;
}