#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int CalculateFromFront(int page) {
    return page/2;
}

int CalculateFromBack(int n, int page) {
    return n/2 - page/2;
}

int main() {
    cin.sync_with_stdio(0);
    
    int n, page;
    
    cin >> n >> page;
    cout << min(CalculateFromFront(page), CalculateFromBack(n, page));
    
    return 0;
}
