#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MyQueue {
public:
  stack<int> s1, s2;
  MyQueue() {};
  void push(int x) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    s2.push(x);
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  };
  int pop() {
    if (s1.empty()) {
      cout << "Can Not Pop,Queue is Empty!" << endl;
      return -1;
    }
    int ele = s1.top();
    s1.pop();
    return ele;
  };
  int top() {
    if (s1.empty()) {
      cout << "Can Not Peek, Queue is Empty!" << endl;
      return -1;
    }
    return s1.top();
  };
  int sizeQ() { return s1.size(); };
  bool isEmptyQ() { return s1.empty(); };
};

int main() {
  MyQueue myq;
  myq.push(1);
  myq.push(2);
  myq.push(3);
  cout << "Top of the queue is : " << myq.top() << endl;
  myq.pop();
  cout << "Top of the queue is : " << myq.top() << endl;
  myq.pop();
  cout << "Top of the queue is : " << myq.top() << endl;
  myq.pop();
  cout << "Queue is Empty : " << boolalpha << myq.isEmptyQ() << endl;
  myq.pop();
  return 0;
}