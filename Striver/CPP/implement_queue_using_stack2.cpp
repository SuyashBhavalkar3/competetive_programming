#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MyQueue {
public:
  stack<int> s1, s2;
  MyQueue() {}

  void push(int x) { s1.push(x); }

  int pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    if (s2.empty()) {
      cout << "Queue is Empty!" << endl;
      return -1;
    }
    int ele = s2.top();
    s2.pop();
    return ele;
  }

  int top() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    if (s2.empty()) {
      cout << "Queue is Empty!" << endl;
      return -1;
    }
    return s2.top();
  }

  int sizeQ() { return s1.size() + s2.size(); }

  bool isEmptyQ() { return s1.empty() && s2.empty(); }
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