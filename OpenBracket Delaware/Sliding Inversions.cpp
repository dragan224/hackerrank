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

const int maxN = 500224;

struct FenwickTree {
  int tree[maxN];
  void update(int idx, int val) {
    while (idx < maxN) {
      tree[idx] += val;
      idx += idx & -idx;
    }
  }
  int get(int idx) {
    int sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= idx & -idx;
    }
    return sum;
  }
} ftree;

int n, m;
int arr[maxN], tmp[maxN];
unordered_map<int, int> hashmap;

void reduce_range() {
  memcpy(tmp, arr, sizeof(arr));
  sort(tmp, tmp + n);
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if (hashmap.find(tmp[i]) == hashmap.end()) {
      hashmap[tmp[i]] = cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    arr[i] = hashmap[arr[i]];
  }
}

int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  reduce_range();
  int i = 0;
  int j = 0;
  long long sum_sol = 0;
  long long sol = 0;
  while (j < n) {
    while (j - i + 1 <= m && j < n) {
      ftree.update(arr[j], +1);
      sol += ftree.get(maxN - 1) - ftree.get(arr[j]);
      j++;
    }
    sum_sol += sol;
    sol -= ftree.get(arr[i] - 1);
    ftree.update(arr[i], -1);
    i++;
  }
  cout << sum_sol << "\n";
  return 0;
}
