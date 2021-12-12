#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define ll long long

int t, n, k;
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
    cin >> n >> k;
    vector<ll> x;
    ll temp;
    for (int i = 1; i <= n; i++) {
      cin >> temp;
      x.push_back(temp);
    }
    sort(x.begin(), x.end());
    bool backward = abs(x[0]) > abs(x[n - 1]);
    ll ans = 0;
    int bag;
    if (n % k == 0) {
      bag = 0;
    } else {
      bag = k - n % k;
    }
    if (backward) {
      int index = n - 1;
      ll now = 0;
      ll prev = 0;
      while (index >= 0) {
        // cout << "prev : " << prev << " next : " << x[index] << endl;
        if (bag == k) {
          ans += abs(prev);
          prev = 0;
          bag = 0;
        }
        ans += abs(prev - x[index]);
        bag++;
        index--;
        now = x[index];
        prev = x[index + 1];
      }
    } else {
      int index = 0;
      ll now = 0;
      ll prev = 0;
      while (index < n) {
        // cout << "prev : " << prev << " next : " << x[index] << " bag : " <<
        // bag
        //      << endl;
        if (bag == k) {
          ans += abs(prev);
          prev = 0;
          bag = 0;
        }
        ans += abs(prev - x[index]);
        bag++;
        index++;
        now = x[index];
        prev = x[index - 1];
        //    cout << "now ans : " << ans << endl;
      }
    }
    cout << ans << endl;
  }
}
