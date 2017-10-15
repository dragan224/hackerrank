#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxN = 400224;
const int maxColor = 4;
const int maxValue = 1e9;

int n, x;
string colors;
vector<int> group[2];

int lis(vector<int> first, vector<int> second) {
  int lis;
  int max_lis;
  if (first.size() <= second.size()) {
    lis = first.size();
    max_lis = 2 * first.size();
    first.push_back(maxValue);
  } else {
    lis = second.size() + 1;
    max_lis = 2 * second.size() + 1;
  }
  int j = 0;
  for (int i = 0; i < first.size() - 1; i++) {
    while (j < second.size() && second[j] < first[i]) j++;
    if (j < second.size() && second[j] < first[i + 1]) {
      lis++;
    }
  }
  return min(lis, max_lis);
}

int main() {
  cin.sync_with_stdio(0);
  cin >> n;
  cin >> colors;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (colors[i] == 'R' || colors[i] == 'B') {
      group[0].push_back(x);
    } else {
      group[1].push_back(x);
    }
  }
  sort(group[0].begin(), group[0].end());
  sort(group[1].begin(), group[1].end());
  cout << max(lis(group[0], group[1]), lis(group[1], group[0])) << endl;
  return 0;
}
