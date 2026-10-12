#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool canEat(vector<int> &piles, int speed, int hours) {
  int hrs = 0;
  for (int pile : piles) {
    hrs += (pile + speed - 1) / speed;
    if (hrs > hours) {
      return false;
    }
  }
  return hrs <= hours;
}

int minBananasToEat(vector<int> &piles, int hours) {
  int left = 1;
  int right = *max_element(piles.begin(), piles.end());
  cout << boolalpha;
  cout << "Right is : " << right << endl;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    cout << "Mid is : " << mid << endl;
    cout << "Can Eat : " << canEat(piles, mid, hours) << endl;
    if (canEat(piles, mid, hours)) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  vector<int> piles = {30, 11, 23, 4, 20};
  int minBananas = minBananasToEat(piles, 5);
  cout << "The Minimum Bananas To Eat To End Up all piles in given hours : "
       << minBananas;
  return 0;
}