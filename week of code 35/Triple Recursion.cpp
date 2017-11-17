#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define msg(x) cout << #x << " = " << x << endl
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          mat[i][j] = m;
        } else if (i > j) {
          mat[i][j] = mat[i-1][j] - 1;
        } else if (j > i) {
          mat[i][j] = mat[i][j-1] - 1;
        } else {
          mat[i][j] = mat[i-1][j-1]+k;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << mat[i][j] << " ";
      }
      cout << "\n";
    }
    return 0;
}