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

const int mod = 1e9 + 7;

const int maxN = 10224;

int dp[2][maxN];
int n, m, k;

inline void mod_add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

inline void mod_sub(int& a, int b) {
  a -= b;
  if (a < 0) a += mod;
}

int main(int argc, char const* argv[]) {
  cin.sync_with_stdio(0);
  cin >> n >> m >> k;
  int sum = 0;
  if (k > n) k = n;
  for (int i = 0; i <= k; i++) {
    dp[0][i] = 1;
  }
  for (int i = 2; i <= m; i++) {
    memset(dp[1], 0, sizeof(dp[1]));
    int csum = 0;
    for (int j = 0; j <= k; j++) {
      mod_add(csum, dp[0][j]);
      dp[1][j] = csum;
    }
    for (int j = k + 1; j <= n; j++) {
      mod_sub(csum, dp[0][j - k - 1]);
      mod_add(csum, dp[0][j]);
      dp[1][j] = csum;
    }
    memcpy(dp[0], dp[1], sizeof(dp[0]));
  }
  cout << dp[0][n] << endl;
  return 0;
}
