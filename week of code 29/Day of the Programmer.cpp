#include <bits/stdc++.h>

using namespace std;

int days_in_month[]  = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int IsLeapYear(int year) {
    if (year < 1918) return (year % 4 == 0);
    return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
}

void Solve(int year) {
    int m = 0;
    int days = 256;
    
    if (year == 1918) {
        m = 2;
        days -= 31+29-13;
    } else {
        days -= IsLeapYear(year);
    }
    while (days > days_in_month[m]) {
        days -= days_in_month[m++];
    }
    
    printf("%.2d.%.2d.%d\n", days, m+1, year);
}

int main(){
    int y;
    cin >> y;
    Solve(y);
    return 0;
}

