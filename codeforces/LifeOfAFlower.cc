#include <iostream>

using namespace std;

#define endl '\n'

int t;
int A[101];

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
  for (int i = 0; i < t; i++) {
    int ans = 1;
    int day;
    cin >> day;
    // cout << "day : " << day << endl;
    for (int d = 1; d <= day; d++) {
      cin >> A[d];
      // cout << "d : " << A[d] << endl;
    }

    for (int now = 1; now <= day; now++) {
      // cout << "now : " << now << endl;
      if (A[now] == 1) {
        if (now - 1 >= 1 && A[now - 1] == 1) {
          ans += 5;
        } else {
          ans++;
        }
      } else {
        if (now - 1 >= 1) {
          if (!A[now - 1] == 1) {
            ans = -1;
            break;
          }
        }
      }
      // cout << "now ans : " << ans << endl;
    }

    cout << ans << endl;
  }
}
