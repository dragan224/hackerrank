#include <bits/stdc++.h>

using namespace std;

bool compare(string A, string B) {
    if (A.size() != B.size()) {
        return A.size() < B.size();
    } else {
        return A < B;
    }
}

int main(){
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    
    sort(unsorted.begin(), unsorted.end(), compare);
    
    for (auto it: unsorted) {
        cout << it << "\n";
    }
   
    return 0;
}

