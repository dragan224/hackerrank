#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define msg(x) cout << #x << " = " << x << endl
using namespace std;

int n;
string name;

bool isLucky(int n) {
  int cnt4 = 0;
  int cnt7 = 0;
  while (n > 0) {
    if (n % 10 == 4) ++cnt4;
    else if (n % 10 == 7) ++cnt7;
    else return false;
    n /= 10;
  }
  return cnt4 == cnt7;
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n;
    int answer = -1;
    string result = "-1";
    while (n--) {
      string name;
      int x;
      cin >> name >> x;
      if (isLucky(x) && (answer == -1 || x < answer)) {
        answer = x;
        result = name;
      }
    }
    cout << result << endl;
    return 0;
}