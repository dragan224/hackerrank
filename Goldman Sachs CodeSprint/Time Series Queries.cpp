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

int n, q;
pair<int, int> ts[maxN], price[maxN];

bool compare_lb(pair<int, int>& p, int value) {
  if (p.first < value) {
    return true;
  }
  return false;
}

int main(int argc, char const* argv[]) {
  cin.sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    ts[i].first = t;
    price[i].second = t;
  }
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    ts[i].second = p;
    price[i].first = p;
  }
  sort(ts, ts + n);
  sort(price, price + n);
  for (int i = n - 2; i >= 0; i--) {
    ts[i].second = max(ts[i].second, ts[i + 1].second);
    price[i].second = min(price[i].second, price[i + 1].second);
  }
  price[n].second = ts[n].second = -1;
  while (q--) {
    int type, value;
    cin >> type >> value;
    if (type == 1) {
      int x = lower_bound(price, price + n, value, compare_lb) - price;  // - price;
      cout << price[x].second;
    } else {
      int x = lower_bound(ts, ts + n, value, compare_lb) - ts;
      cout << ts[x].second;
    }
    cout << "\n";
  }
  return 0;
}
