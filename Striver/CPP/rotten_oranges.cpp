#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int rotten_oranges(vector<vector<int>> &matrix) {
  queue<pair<int, int>> queue;
  int n = matrix.size();
  int m = matrix[0].size();
  int fresh = 0;
  int time = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 2) {
        queue.push({i, j});
      } else if (matrix[i][j] == 1) {
        fresh++;
      }
    }
  }
  vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  while (!queue.empty() && fresh > 0) {
    int size = queue.size();
    for (int i = 0; i < size; i++) {
      int r = queue.front().first;
      int c = queue.front().second;
      queue.pop();
      for (auto &dir : directions) {
        int nr = r + dir[0];
        int nc = c + dir[1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] == 1) {
          matrix[nr][nc] = 2;
          fresh--;
          queue.push({nr, nc});
        }
      }
    }
    time++;
  }
  if (fresh > 0) {
    return -1;
  }
  return time;
}

int main() {
  vector<vector<int>> matrix = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  int timeForAllOrangesRotten = rotten_oranges(matrix);
  cout << "The Time Taken For All Oranges To Be Rotten Is : "
       << timeForAllOrangesRotten << endl;
  return 0;
}