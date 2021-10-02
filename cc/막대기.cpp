#include <iostream>

using namespace std;

#define endl '\n'

int N;

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

void input() { cin >> N; }

void solve() {
  int answer = 0;
  int x = 0b1;
  for (int i = 0; i <= 6; i++) {
    if ((N & x)) {
      answer++;
    }
    x = x << 1;
  }
  cout << answer;
}
