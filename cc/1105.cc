#include <iostream>

#define endl '\n'

using namespace std;

string L, R;

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> L >> R; }

void solve() {
  int ans = 0;
  if (L.length() == R.length()) {
    for (int index = 0; index < L.length(); index++) {
      if (L[index] != R[index]) {
        break;
      }
      if (L[index] == '8') {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
