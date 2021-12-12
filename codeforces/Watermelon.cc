#include <iostream>

using namespace std;

#define endl '\n'

int w;
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

void input() { cin >> w; }

void solve() {
  if (w >= 4 && w % 2 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
