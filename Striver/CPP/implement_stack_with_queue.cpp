#include<iostream>
#include<queue>

using namespace std;

class QueueClass{
    queue<int> qt;
    public:
        void push(int x){
            qt.push(x);
            for(int i=0;i<qt.size()-1;i++){
                qt.push(qt.front());
                qt.pop();
            }
        }
        int pop(){
            if(qt.empty()){
                cout<<"Stack is empty"<<endl;
            }
            int ele = qt.front();
            qt.pop();
            return ele;
        }
        int top(){
            if(qt.empty()){
                cout<<"Stack is empty"<<endl;
            }
            return qt.front();
        }
        bool isEmpty(){
            return qt.empty();
        }
};

int main(){
    QueueClass stack;
    stack.push(4);
    stack.push(9);
    stack.push(5);
    stack.push(2);
    cout<<"Top of the stack is : "<<stack.top()<<endl;
    stack.pop();
    stack.pop();
    cout<<"Top of the stack is : "<<stack.top()<<endl;
    stack.push(1);
    cout<<"Top of the stack is : "<<stack.top()<<endl;
}