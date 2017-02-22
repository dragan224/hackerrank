#include <bits/stdc++.h>

using namespace std;

bool isInCircle(int circleX, int circleY, int r, int x, int y) {
    if ((x-circleX)*(x-circleX) + (y-circleY)*(y-circleY) <= r * r) {
        return true;
    }
    return false;
}

int ccw(int Ax, int Ay, int Bx, int By, int Cx, int Cy) {
    return Ax*(By-Cy) + Bx*(Cy-Ay) + Cx*(Ay-By);
}

bool isInSquare(int x1, int y1, int x3, int y3, int x, int y) {
    int x2 = (x1+x3+y3-y1) / 2;
    int y2 = (y1+y3+x1-x3) / 2;
    int x4 = (x1+x3+y1-y3) / 2;
    int y4 = (y1+y3+x3-x1) / 2;
    
    int v1 = ccw(x1, y1, x2, y2, x, y); 
    int v2 = ccw(x2, y2, x3, y3, x, y);
    int v3 = ccw(x3, y3, x4, y4, x, y);
    int v4 = ccw(x4, y4, x1, y1, x, y);
    
    if (v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 ||
        v1 < 0 && v2 < 0 && v3 < 0 && v4 < 0) return true;
    
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    int w;
    int h;
    cin >> w >> h;
    int circleX;
    int circleY;
    int r;
    cin >> circleX >> circleY >> r;
    int x1;
    int y1;
    int x3;
    int y3;
    cin >> x1 >> y1 >> x3 >> y3;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (isInCircle(circleX, circleY, r, j, i) || isInSquare(x1, y1, x3, y3, j, i)) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout <<"\n";
    }
    return 0;
}

