#include <iostream>

using namespace std;

#define endl '\n'

int n;
void input();
void solve();
void dfs(int left, int numbers, int max_numbers);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> n; }

void solve() {
  for (int i = 1; i <= 4; i++) {
    dfs(n, 0, i);
  }
}

void dfs(int left, int numbers, int max_numbers) {
  if (max_numbers == numbers) {
    if (left == 0) {
      cout << max_numbers << endl;
      exit(0);
    }
    return;
  }

  int i = 1;
  while (left >= i * i) {
    dfs(left - i * i, numbers + 1, max_numbers);
    i++;
  }
  return;
}
