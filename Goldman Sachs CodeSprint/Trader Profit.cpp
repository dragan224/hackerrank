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

const int maxN = 30;
const int maxK = 11;

int q, k, n;
int arr[maxN];
int best[maxN][maxK];

int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin >> q;
  while (q--) {
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    memset(best, 0, sizeof(best));
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        for (int j = 0; j <= k; j++) {
          best[i][j] = best[i - 1][j];
        }
      }
      for (int K = 0; K < k; K++) {
        for (int j = i - 1; j >= 1; j--) {
          best[i][K + 1] = max(best[i][K + 1], best[j - 1][K] + arr[i] - arr[j]);
        }
        best[i][1] = max(best[i][1], arr[i] - arr[0]);
      }
    }
    int best_ans = 0;
    for (int i = 0; i <= k; i++) {
      best_ans = max(best_ans, best[n - 1][i]);
    }
    cout << best_ans << endl;
  }
  return 0;
}
