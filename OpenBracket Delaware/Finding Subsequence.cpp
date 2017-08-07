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
const int maxAlpha = 26;

string str;
int k;
char largest[maxN];
int last_occurance[maxAlpha];
int cnt[maxN][maxAlpha];

int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin >> str;
  cin >> k;
  for (int i = 0; i < maxAlpha; i++) {
    last_occurance[i] = -1;
  }
  for (int i = str.size() - 1; i >= 0; i--) {
    int c = str[i] - 'a';
    if (last_occurance[c] == -1) {
      last_occurance[c] = i;
    }
    for (int j = 0; j < maxAlpha; j++) {
      cnt[i][j] = cnt[i + 1][j];
    }
    cnt[i][c]++;
    largest[i] = largest[i + 1];
    if (cnt[i][str[i] - 'a'] >= k) {
      largest[i] = max(largest[i + 1], str[i]);
    }
  }
  string answer;
  for (int i = 0; i < str.size();) {
    char c = largest[i];
    if (c == 0) break;
    for (int j = 0; j < cnt[i][c - 'a']; j++) {
      answer.push_back(c);
    }
    i = last_occurance[c - 'a'] + 1;
  }
  cout << answer << "\n";
  return 0;
}
