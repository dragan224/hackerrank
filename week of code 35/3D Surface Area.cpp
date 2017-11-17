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

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool isIn(int x, int y, int h, int w) {
  return 0 <= x && x < h && 0 <= y && y < w;
}

int main() {
    cin.sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    vector<vector<int> > toy(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> toy[i][j];
      }
    }
    int surface = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (toy[i][j] > 0) {
          surface += 2; // bottom & top
          for (int k = 1; k <= toy[i][j]; k++) {
            surface += 4;
            for (int d = 0; d < 4; d++) {
              int x = i + dx[d];
              int y = j + dy[d];
              if (isIn(x, y, h, w) && toy[x][y] >= k) {
                --surface;
              }
            }
          }
        }
      }
    }
    cout << surface << endl;
    return 0;
}