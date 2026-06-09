// Implement a first in first out (FIFO) queue using only two stacks.
// The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:

// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.

// Look For Reference In the Book On Pg No 36-37-38


#include<iostream>
#include<stack>

using namespace std;

class MyQueue{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        MyQueue(){};
        void push(int x){
            while(!s1.empty()){
                int val = s1.top();
                s2.push(val);
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                int val2 = s2.top();
                s1.push(val2);
                s2.pop();
            }
        }

        int pop(){
            int popped = s1.top();
            s1.pop();
            return popped;
        }

        int top(){
            return s1.top();
        }

        bool isempty(){
            return s1.empty();
        }
};

int main(){
    MyQueue queObj;
    queObj.push(1);
    queObj.push(2);
    queObj.push(3);
    cout<<queObj.top()<<endl;
    cout<<queObj.pop()<<endl;
    cout<<queObj.top()<<endl;
    cout<<queObj.isempty();
}