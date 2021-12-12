#include <iostream>

using namespace std;

#define endl '\n'

void input();
void solve();

int n, m, a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> n >> m >> a; }

void solve() {
  long long row, col;
  if (n % a == 0) {
    row = n / a;
  } else {
    row = n / a + 1;
  }
  if (m % a == 0) {
    col = m / a;
  } else {
    col = m / a + 1;
  }
  cout << row * col << endl;
}
