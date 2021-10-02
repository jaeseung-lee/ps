#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define mod 10007

int N;
int dp[1001 + 1][10];

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
  // boundary
  for (int i = 0; i <= 9; i++) {
    dp[1][i] = 1;
  }

  // fill_up
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= 9; j++) {
      dp[i][j] = 0;
      for (int k = 0; k <= j; k++) {
        dp[i][j] += dp[i - 1][k];
      }
      dp[i][j] %= mod;
    }
  }

  int answer = 0;
  for (int i = 0; i <= 9; i++) {
    answer += dp[N][i];
  }
  answer %= mod;
  cout << answer;
}
