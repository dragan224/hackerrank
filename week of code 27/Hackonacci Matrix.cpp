#include <iostream>
using namespace std;

const int MAX_N = 2016;

int hack(int i) {
  if (i % 7 == 0 || i % 7 == 1 || i % 7 == 6) return 1;
  return 0;
}

struct Matrix {
  int data[MAX_N][MAX_N];
  int n;
  void init(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        data[i][j] = hack((i+1)*(j+1));
      }
    }
  }
  int calcDiff(Matrix other) {
    int diff = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (data[i][j] != other.data[i][j]) {
          diff++;
        }
      }
    }
        return diff;
  }
  void rotate90left() {
    for (int x = 0; x < n / 2; x++) { 
        for (int y = x; y < n-x-1; y++) {
              int temp = data[x][y];
        data[x][y] = data[y][n-1-x];
        data[y][n-1-x] = data[n-1-x][n-1-y];
        data[n-1-x][n-1-y] = data[n-1-y][x];
        data[n-1-y][x] = temp;
          }
      }
  }
};

int diff[4];
int n;
Matrix A, B;

void precompute(int n) {
  A.init(n);
  B.init(n);
  for (int i = 3; i > 0; i--) {
    B.rotate90left();
    diff[i] = A.calcDiff(B);  
  }
}

int q, angle;

int main() {
  cin.sync_with_stdio(0);
  cin >> n;
  precompute(n);
  cin >> q;
  while (q--) {
    cin >> angle;
    angle = (angle % 360) / 90;
    cout << diff[angle] << "\n";
  }
  return 0;
}
