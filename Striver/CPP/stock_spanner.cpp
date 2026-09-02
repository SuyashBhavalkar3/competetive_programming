#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Stock_Spanner {
  stack<pair<int, int>> st;
  int ind = -1;

public:
  Stock_Spanner() { ind = -1; }
  int next(int val) {
    ind++;
    while (!st.empty() && st.top().first <= val) {
      st.pop();
    }
    int pge = st.empty() ? -1 : st.top().second;
    int ele = ind - pge;
    st.push({val, ind});
    return ele;
  }
};

int main() {
  Stock_Spanner stockSpanner;
  cout << "The Maximum Stock Span Is : " << stockSpanner.next(100)
       << endl; // return 1
  cout << "The Maximum Stock Span Is : " << stockSpanner.next(80)
       << endl; // return 1
  cout << "The Maximum Stock Span Is : " << stockSpanner.next(60)
       << endl; // return 1
  cout << "The Maximum Stock Span Is : " << stockSpanner.next(70)
       << endl; // return 2
  cout << "The Maximum Stock Span Is : " << stockSpanner.next(60)
       << endl; // return 1
  cout << "The Maximum Stock Span Is : " << stockSpanner.next(75)
       << endl; // return 4
  cout << "The Maximum Stock Span Is : " << stockSpanner.next(65)
       << endl; // return 1
  cout << "The Maximum Stock Span Is : " << stockSpanner.next(80)
       << endl; // return 7
  cout << "The Maximum Stock Span Is : " << stockSpanner.next(85)
       << endl; // return 8
  cout << "The Maximum Stock Span Is : " << stockSpanner.next(100)
       << endl; // return 10
  return 0;
}