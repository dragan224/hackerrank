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

const int maxN = 100224;

pair<int, int> a[maxN];
int max_idx[maxN];

int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  int n, stock_price;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a, a + n);
  max_idx[0] = a[0].second;
  for (int i = 1; i < n; i++) {
    max_idx[i] = max(max_idx[i - 1], a[i].second);
  }
  int q, x;
  cin >> q;
  while (q--) {
    cin >> x;
    if (x < a[0].first) {
      cout << -1;
      cout << "\n";
      continue;
    }
    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      if (a[mid].first <= x) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    cout << max_idx[lo];
    cout << "\n";
  }
  return 0;
}
