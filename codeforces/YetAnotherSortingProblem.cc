#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int t, n;
int A[500001];
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
    int temp;
    for (int i = 1; i <= n; i++) {
      cin >> A[i];
    }
    if (n < 3) {
      if (n == 3) {
        if (A[1] <= A[2] && A[2] <= A[3]) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      } else if (n == 1) {
        cout << "YES" << endl;
      } else {
        if (A[1] <= A[2]) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    } else {
      int now = 1;
      bool is_answer = true;
      while (now <= n) {
        if (A[now] != now) {
          int j = now + 1;
          for (j; j <= n; j++) {
            if (A[j] != j) {
              break;
            }
          }
          int k = j + 1;
          for (k; k <= n; k++) {
            if (A[k] != k) {
              break;
            }
          }
          if (j <= n && k <= n) {
            int temp = A[k];
            A[k] = A[j];
            A[j] = A[now];
            A[now] = temp;
          } else {
            is_answer = false;
            break;
          }
        } else {
          now++;
        }
      }
      if (is_answer) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
