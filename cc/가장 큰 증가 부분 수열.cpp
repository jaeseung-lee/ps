#include <iostream>

using namespace std;

#define endl '\n'

int N;
int A[1001];
int dp[1001];

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
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
}

void solve() {
  dp[1] = A[1];

  for (int i = 2; i <= N; i++) {
    dp[i] = A[i];
    for (int j = 1; j <= i - 1; j++) {
      if (A[j] < A[i] && dp[j] + A[i] > dp[i]) {
        dp[i] = dp[j] + A[i];
      }
    }
  }

  int answer = dp[1];
  for (int i = 2; i <= N; i++) {
    if (answer < dp[i]) {
      answer = dp[i];
    }
  }

  cout << answer;
}
