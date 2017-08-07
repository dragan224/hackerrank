#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > matrix;
vector<vector<int> > rightmost;

void init(vector<vector<int> >& mat, int n, int m) {
  mat.clear();
  mat.reserve(n * m + 10);
  for (int i = 0; i < n; i++) {
    mat.push_back(vector<int>(m, 0));
  }
}

void precompute() {
  init(rightmost, n, m);
  for (int i = 0; i < n; i++) {
    rightmost[i][m - 1] = m - 1;
    for (int j = m - 2; j >= 0; j--) {
      rightmost[i][j] = j;
      if (matrix[i][j] <= matrix[i][j + 1]) {
        rightmost[i][j] = rightmost[i][j + 1];
      }
    }
  }
}

long long row_count(int row) {
  long long cnt = 0;
  for (int i = 0; i < m; i++) {
    int j = i;
    while (j < m - 1 && matrix[row][j + 1] >= matrix[row][j]) j++;
    int down = row;
    for (; j >= i; j--) {
      while (down < n - 1 && matrix[down][j] <= matrix[down + 1][i] && rightmost[down + 1][i] >= j) down++;
      cnt += down - row + 1;
    }
  }
  return cnt;
}

long long column_count(int col) {
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    int down = m;
    for (int j = i; j < n; j++) {
      if (j > i && matrix[j][col] < matrix[j - 1][col]) break;
      down = min(down, rightmost[j][col]);
      while (j > i && matrix[j - 1][down] > matrix[j][col] && down > col) down--;
      cnt += down - col + 1;
    }
  }
  return cnt;
}

int main(int argc, char const* argv[]) {
  cin.sync_with_stdio(0);
  cin >> n >> m;
  init(matrix, n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }
  precompute();
  long long ans = 0;
  if (n < m) {
    for (int i = 0; i < n; i++) {
      ans += row_count(i);
    }
  } else {
    for (int j = 0; j < m; j++) {
      ans += column_count(j);
    }
  }
  cout << ans << "\n";
  return 0;
}
