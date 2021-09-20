#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int n;
int A[10000 + 1];
int dp[10000 + 1];

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
    cin >> A[i];
  }
}

void solve() {
  // boundary
  dp[0] = 0;
  dp[1] = A[1];
  dp[2] = A[1] + A[2];
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (dp[i] < dp[i - 2] + A[i]) {
      dp[i] = dp[i - 2] + A[i];
    }
    if (dp[i] < dp[i - 3] + A[i - 1] + A[i]) {
      dp[i] = dp[i - 3] + A[i - 1] + A[i];
    }
  }
  cout << dp[n];
}
