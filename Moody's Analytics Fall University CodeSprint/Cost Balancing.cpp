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

unordered_map<int, int> pay;

int main() {
  cin.sync_with_stdio(0);
  int n;
  int m;
  cin >> n >> m;
  int sum = 0;
  for (int a0 = 0; a0 < n; a0++) {
    int id_number;
    int amount;
    cin >> id_number >> amount;
    pay[id_number] += amount;
    sum += amount;
  }
  int required = sum / m;
  for (int i = 1; i <= m; i++) {
    cout << i << " ";
    if (i == 1)
      cout << pay[i] - sum / m - sum % m;
    else
      cout << pay[i] - sum / m;
    cout << "\n";
  }
  return 0;
}
