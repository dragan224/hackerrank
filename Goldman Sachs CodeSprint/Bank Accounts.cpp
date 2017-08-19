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

int q, n, k, x, p;
double d;

int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin >> q;
  while (q--) {
    cin >> n >> k >> x >> d;
    double sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> p;
      sum += max(1. * x * p / 100, 1. * k);
    }
    sum <= d ? puts("fee") : puts("upfront");
  }
  return 0;
}
