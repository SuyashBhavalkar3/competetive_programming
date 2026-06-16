#include <iostream>

using namespace std;

double find_power(int m, double mid) {
  double ans = 1;
  for (int i = 1; i <= m; i++) {
    ans = ans * mid;
  }
  return ans;
}

int findNthRoot(int n, int m) {
  double low = 1;
  double high = n;
  double diff = 1e-6;
  while ((high - low) > diff) {
    double mid = low + (high - low) / 2;
    int power = find_power(m, mid);
    if (power > n) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return low + (high - low) / 2;
}

int main() {
  int n = 27;
  int m = 3;
  int N = findNthRoot(n, m);
  cout << N << endl;
  return 0;
}