#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int q;
long long n;

int main() {
    cin.sync_with_stdio(0);
    cin >> q;
    while (q--) {
        cin >> n;
        long long res = 0;
        for (long long i = 0; i < 50 ; i++) {
            long long j = 1LL<<i;
            if (n & j) continue;
            if (n < j) break;
            res += 1LL << i;    
        }
        cout << res << "\n";
    }
    return 0;
}

