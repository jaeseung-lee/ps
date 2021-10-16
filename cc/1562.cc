#include <iostream>

using namespace std;

#define endl '\n'
#define mod 1000000000

int N;
int dp[101][1024][10];

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
  for (int i = 1; i <= 9; i++) {
    dp[1][(1 << i)][i] = 1;
  }
  for (int n = 2; n <= 100; n++) {
    for (int i = 0; i < 1024; i++) {
      if ((i & 1) == 1) {
        dp[n][i][0] = dp[n - 1][i | (1 << 0)][1];
        dp[n][i][0] += dp[n - 1][i & (~(1 << 0))][1];
        dp[n][i][0] %= mod;
      }
    }
    for (int j = 1; j <= 8; j++) {
      for (int i = 0; i < 1024; i++) {
        if (((i >> j) & 1) == 1) {
          dp[n][i][j] += dp[n - 1][i | (1 << j)][j - 1];
          dp[n][i][j] += dp[n - 1][i & (~(1 << j))][j - 1];
          dp[n][i][j] %= mod;
          dp[n][i][j] += dp[n - 1][i | (1 << j)][j + 1];
          dp[n][i][j] %= mod;
          dp[n][i][j] += dp[n - 1][i & (~(1 << j))][j + 1];
          dp[n][i][j] %= mod;
        }
      }
    }
    for (int i = 0; i < 1024; i++) {
      if (((i >> 9) & 1) == 1) {
        dp[n][i][9] = dp[n - 1][i | (1 << 9)][8];
        dp[n][i][9] += dp[n - 1][i & (~(1 << 9))][8];
        dp[n][i][9] %= mod;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= 9; i++) {
    ans += dp[N][1023][i];
    ans %= mod;
  }
  cout << ans << endl;
}
