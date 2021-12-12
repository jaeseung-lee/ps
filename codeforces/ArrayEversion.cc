#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int t, n;
vector<int> A(200001, 0);

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

void input() { cin >> t; }

void solve() {
  for (int T = 0; T < t; T++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> A[i];
    }
    int x = A[n];
    int ans = 0;
    for (int i = n; i >= 1; i--) {
      if (x < A[i]) {
        x = A[i];
        ans++;
      }
    }
    cout << ans << endl;
  }
}
