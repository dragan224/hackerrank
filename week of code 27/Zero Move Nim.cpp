#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int q, n;
int p[100224];

int main() {
    cin >> q;
    while (q--) {
        cin >> n;
        int xorsum = 0;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (p[i] & 1) p[i]++;
            else p[i]--;
            xorsum ^= p[i];
        }
        if (xorsum) cout << "W";
        else cout << "L";
        cout << "\n";
    }
    
    return 0;
}

