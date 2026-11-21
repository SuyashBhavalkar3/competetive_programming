#include<iostream>
#include<vector>

using namespace std;

bool lemonadeChange(vector<int>& bills){
    int fiveBill = 0;
    int tenBill = 0;
    for(int bill : bills){
        if(bill == 5){
            fiveBill++;
        }
        else if(bill == 10){
            if(fiveBill>=1){
                fiveBill--;
                tenBill++;
            }
            else{
                return false;
            }
        }
        else{
            if(fiveBill>=1 && tenBill>=1){
               fiveBill--;
               tenBill--;
            }
            else if(fiveBill>=3){
                fiveBill-=3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> bills = {5, 5, 5, 10, 20};
    bool result = lemonadeChange(bills);
    cout<<boolalpha;
    cout<<"The Lemonade Exchange Can Happen : "<<result<<endl;
    return 0;
}