#include <iostream>
#include <string>

using namespace std;

#define endl '\n'
#define ll long long

int t;
ll a, s;
ll pow10[36];
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

void input() {
  cin >> t;
  ll value = 1;
  for (int i = 0; i <= 36; i++) {
    pow10[i] = value;
    value *= 10;
  }
}

void solve() {
  while (t > 0) {
    t--;
    cin >> a >> s;
    ll ans = 0;
    int max_index = to_string(a).length();
    while (a > 0) {
      int now = a % 10;
      cout << "a : " << a << endl;
      cout << "now : " << now << endl;
      cout << "s : " << s << endl;
      if (now <= s % 10) {
        ans = ans * 10 + s % 10 - now;
        s = s / 10;
        a = a / 10;
      } else {
        if (s % 100 < 20 && s % 100 >= 10) {
          ans = ans * 10 + s % 100 - now;
          s = s / 100;
          a = a / 10;

        } else {
          ans = -1;
          break;
        }
      }
      cout << "ans : " << ans << endl << endl;
    }
    if (ans != -1) {
      ans += ans * pow10[to_string(s).length()] + s;
    }
    cout << ans << endl;
  }
}
