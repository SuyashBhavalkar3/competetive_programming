#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
  int start, end, size, currsize;
  vector<int> queue;

public:
  Queue(int s) {
    size = s;
    queue.resize(size);
    start = -1;
    end = -1;
    currsize = 0;
  }
  void push(int val) {
    if (currsize == size) {
      cout << "Cannot Push, Queue Overflow!" << endl;
      return;
    }
    if (currsize == 0) {
      start = 0;
      end = 0;
    } else {
      end = (end + 1) % size;
    }
    currsize++;
    queue[end] = val;
  }
  void pop() {
    if (currsize == 0) {
      cout << "Cannot Pop, Queue Underflow!" << endl;
      return;
    }
    currsize--;
    if (currsize == 0) {
      start = -1;
      end = -1;
    } else {
      start = (start + 1) % size;
    }
  }
  int top() {
    if (currsize == 0) {
      cout << "Queue is empty!" << endl;
      return -1;
    }
    return queue[start];
  }
  bool isEmpty() { return currsize == 0; }
};

int main() {
  Queue que(5);
  que.push(10);
  que.push(20);
  que.push(30);
  cout << que.top() << endl;

  que.pop();

  cout << que.top() << endl;

  que.push(40);
  que.push(50);
  que.push(60);

  cout << boolalpha;
  cout << que.isEmpty() << endl;

  que.push(70);

  while (!que.isEmpty()) {
    cout << que.top() << " ";
    que.pop();
  }

  cout << endl;
}