#include <iostream>

using namespace std;

#define endl '\n'

int N;
int A[101];
int op[4];
void input();
void solve();

int MIN = 1000000001;
int MAX = -1000000001;

void dfs(int index, int plus, int minus, int mul, int div, int value);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();
  return 0;
}

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < 4; i++) {
    cin >> op[i];
  }
}

void solve() {
  dfs(2, op[0], op[1], op[2], op[3], A[1]);
  cout << MAX << endl;
  cout << MIN << endl;
}

void dfs(int index, int plus, int minus, int mul, int div, int value) {
  if (index > N) {
    if (MAX < value) {
      MAX = value;
    }
    if (MIN > value) {
      MIN = value;
    }
    return;
  }

  if (plus > 0) {
    dfs(index + 1, plus - 1, minus, mul, div, value + A[index]);
  }
  if (minus > 0) {
    dfs(index + 1, plus, minus - 1, mul, div, value - A[index]);
  }
  if (mul > 0) {
    dfs(index + 1, plus, minus, mul - 1, div, value * A[index]);
  }
  if (div > 0) {
    dfs(index + 1, plus, minus, mul, div - 1, value / A[index]);
  }
  return;
}
