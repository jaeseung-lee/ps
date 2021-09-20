#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int n;
int A[500 + 1][500 + 1];
int dp[500 + 1][500 + 1];

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
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> A[i][j];
    }
  }
}

void solve() {
  dp[1][1] = A[1][1];
  for (int i = 2; i <= n; i++) {
    dp[i][1] = dp[i - 1][1] + A[i][1];
    for (int j = 2; j <= i; j++) {
      if (dp[i - 1][j - 1] > dp[i - 1][j]) {
        dp[i][j] = dp[i - 1][j - 1] + A[i][j];
      } else {
        dp[i][j] = dp[i - 1][j] + A[i][j];
      }
    }
    dp[i][i] = dp[i - 1][i - 1] + A[i][i];
  }

  int answer = dp[n][1];
  for (int i = 2; i <= n; i++) {
    if (answer < dp[n][i]) {
      answer = dp[n][i];
    }
  }
  cout << answer;
}
