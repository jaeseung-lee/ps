#include <iostream>

#define endl '\n'

using namespace std;

int E, S, M;
int e, s, m, answer;

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

void input() { cin >> E >> S >> M; }

void solve() {
  e = 1;
  s = 1;
  m = 1;
  answer = 1;

  while (true) {
    if (e == E && s == S && m == M) {
      break;
    } else {
      e++;
      s++;
      m++;
      if (e >= 16) {
        e -= 15;
      }
      if (s >= 29) {
        s -= 28;
      }
      if (m >= 20) {
        m -= 19;
      }
      answer++;
    }
  }
  cout << answer;
}
