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

const int maxN = 300224;

int n, k;
long long a[maxN];
long long dp[maxN];
deque<int> convex_hull;

int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[1] = a[1];
  convex_hull.push_back(1);
  for (int i = 2; i <= n; i++) {
    while (convex_hull.size() > 1) {
      int f = convex_hull[0];
      int s = convex_hull[1];
      if (dp[f] - 1LL * (i - f - 1) * k * (i - f - 1) < dp[s] - 1LL * (i - s - 1) * k * (i - s - 1)) {
        convex_hull.pop_front();
      } else {
        break;
      }
    }
    dp[i] = a[i];
    for (auto it : convex_hull) {
      dp[i] = max(dp[i], -(i - it - 1) * 1LL * k * (i - it - 1) + dp[it] + a[i]);
    }
    while (convex_hull.size() > 0 && dp[i] > dp[convex_hull.back()]) {
      convex_hull.pop_back();
    }
    convex_hull.push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    dp[n] = max(dp[n], dp[i]);
  }
  cout << dp[n] << endl;
  return 0;
}
