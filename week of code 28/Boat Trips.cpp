#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, c, p;


int main() {
    cin.sync_with_stdio(0);
    cin >> n >> c >> m;
    bool can_transport = true;
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (p > m * c) can_transport = false;
    }
    can_transport ? puts("Yes") : puts("No");
    return 0;
}

