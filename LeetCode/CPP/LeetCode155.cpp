// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.


#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class minStack{
    private:
        stack<int> s;
        int minValue;
    public:
        minStack(){
            minValue=0;
        }
        void push(int val){
            if(s.empty()){
                s.push(val);
                minValue = val;
            }
            else{
                if(val<minValue){
                    s.push(2*val - minValue);
                    minValue = val;
                }
                else{
                    s.push(val);
                }
            }
        }
        int getMin(){
            return minValue;
        }
        int top(){
            if(s.top()<minValue){
                return minValue;
            }
            else{
                s.top();
            }
        }
        void pop(){
            if(s.top()<minValue){
                minValue = 2*minValue - s.top();
            }
            s.pop();
        }
};

int main(){
    minStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);

    cout << "Min: " << ms.getMin() << endl;
    ms.pop();
    cout << "Top: " << ms.top() << endl;
    cout << "Min: " << ms.getMin() << endl;
    return 0;
}