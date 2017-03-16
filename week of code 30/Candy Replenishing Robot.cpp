#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int t;
    cin >> n >> t;
    vector<int> c(t);
    for(int c_i = 0; c_i < t; c_i++){
       cin >> c[c_i];
    }
    int current_candy = n;
    int added_candy = 0;
    for (auto it: c) {
        if (current_candy < 5) {
            added_candy += n - current_candy;
            current_candy = n;
        }
        current_candy = max(0, current_candy - it);
    }
    cout << added_candy << endl;
    return 0;
}

