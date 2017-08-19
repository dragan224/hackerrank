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

const int maxN = 100244;

int n;
pair<int, int> arr[maxN];
long long k;

int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i + 1;
  }
  sort(arr, arr + n);
  cin >> k;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long stock = min(1LL * arr[i].second, k / arr[i].first);
    ans += stock;
    k -= stock * arr[i].first;
  }
  cout << ans << endl;
  return 0;
}
