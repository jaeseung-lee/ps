#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

int t;
void input();
void solve();

int gcd(int x, int y) {
  int M = max(x, y);
  int m = min(x, y);
  if (M % m == 0) {
    return m;
  } else {
    return gcd(m, M % m);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> t; }

void solve() {
  for (int _x = 0; _x < t; _x++) {
    int n;
    cin >> n;
    // cout << "n : " << n << endl;
    int a, b, c = 1;
    bool searched = false;
    for (c = 1; c < n && !searched; c++) {
      if (n % c == 0) {
        // cout << "c : " << c << endl;
        int value = n - c;
        for (int A = 1; A < value / 2; A++) {

          if (gcd(A, value - A) == c && A != c && value - A != c) {
            a = A;
            b = value - A;
            searched = true;
            break;
          }
        }
      }
    }
    cout << a << " " << b << " " << c - 1 << endl;
  }
}
