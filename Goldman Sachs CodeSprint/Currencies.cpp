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

const int maxN = 25;
const int mod = 1e9 + 7;

int n, x, s, f, m;
int rates[maxN][maxN];
double e[maxN][maxN][maxN];
int go[maxN][maxN][maxN];

int mul(int s, int f, int l) {
  if (l == 1) {
    assert(go[s][f][l] == f);
    return rates[s][f];
  }
  int ans = mul(s, go[s][f][l], l - 1) % mod;
  ans = 1LL * ans * mul(go[s][f][l], f, l - 1) % mod;
  return ans;
}

int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin >> n;
  cin >> x >> s >> f >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> e[i][j][1];
      if (e[i][j][1] != 0) {
        rates[i][j] = e[i][j][1];
        e[i][j][1] = log(e[i][j][1]);
      }
      go[i][j][1] = j;
    }
  }
  for (int l = 2; l <= n + 1; l++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        e[i][j][l] = e[i][j][l - 1];
        go[i][j][l] = go[i][j][l - 1];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (e[i][j][l] < e[i][k][l - 1] + e[k][j][l - 1]) {
            e[i][j][l] = e[i][k][l - 1] + e[k][j][l - 1];
            go[i][j][l] = k;
          }
        }
      }
    }
  }
  int best_l = 0;
  long long best_sum = 0;
  for (int l = 1; l <= n + 1; l++) {
    if (l > m) continue;
    long long sum = e[s][f][l] + 1LL * (m - 1) / (2 * l) * (e[s][f][l] + e[f][s][l]);
    if (sum > best_sum) {
      best_sum = sum;
      best_l = l;
    }
  }
  long long half = mul(s, f, best_l);
  long long full = 1LL * mul(s, f, best_l) * mul(f, s, best_l) % mod;
  int cnt = (1LL * (m - 1) / (2 * best_l)) % mod;
  long long sum = (half + full * cnt) % mod;
  cout << sum * x % mod << endl;
  return 0;
}
