#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int n, p;
int a[100224];

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long last_used = 0;
    sort(a, a + n);
    long long int res = 0;
    
    for (int i = 0; i < n; i++) {
        long long cnt = (a[i] + p - 1) / p;
        if (cnt > last_used) {
            last_used = cnt;
            res += cnt;
        } else {
            last_used++;
            res += last_used;
        }
    }
    cout << res << "\n";
    return 0;
}

