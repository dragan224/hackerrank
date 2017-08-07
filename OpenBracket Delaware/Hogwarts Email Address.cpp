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

string str;

int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin >> str;
  regex_match(str, regex("([a-z]){5}(@hogwarts\\.com)")) ? puts("Yes") : puts("No");
  return 0;
}
