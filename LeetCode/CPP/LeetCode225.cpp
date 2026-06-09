// Implement a last-in-first-out (LIFO) stack using only two queues.
// The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.


// Look For Reference In the Book On Pg No 31-32

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    void printQueue() {
        queue<int> temp = q;
        cout << "[ ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "]" << endl;
    }
};

int main() {
    MyStack stackObj;

    stackObj.push(1);
    stackObj.push(2);
    stackObj.push(3);

    cout << "Current stack (front is top): ";
    stackObj.printQueue();

    cout << "Top element: " << stackObj.top() << endl;
    cout << "Popped: " << stackObj.pop() << endl;

    cout << "After pop, stack: ";
    stackObj.printQueue();

    cout << "Is empty? " << (stackObj.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
