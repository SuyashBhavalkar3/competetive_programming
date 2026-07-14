#include<iostream>
#include<vector>

using namespace std;

class Stack{
    private:
        vector<int> stack;
        int size;
        int top;
    public:
    Stack(int s){
            size = s;
            top = -1;
            stack.resize(size);
    };
    void push(int val){
        if(top == size - 1){
            cout<<"Stack Overflow, Cannot Push!"<<endl;
            return;
        };
        stack[++top] = val;
    };
    void pop(){
        if(top == -1){
            cout<<"Stack Underflow, Cannot PoP!"<<endl;
            return;
        };
        top--;
    };
    int peek(){
        if(top == -1){
            cout<<"Stack is empty!"<<endl;
            return -1;
        };
        return stack[top];
    };
    bool isEmpty(){
        return top == -1;
    };
};

int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.peek() << endl;
    st.pop();
    cout << "Top after pop: " << st.peek() << endl;
    return 0;
}