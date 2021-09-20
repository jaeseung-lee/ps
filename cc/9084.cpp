#include <iostream>

using namespace std;

#define endl '\n'

int T;
int N;
int Coin[21];
int target;
unsigned int dp[10000][21];

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    input();
    solve();
  }

  return 0;
}

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> Coin[i];
  }
  cin >> target;
}

void solve() {
  // init
  for (int i = 0; i <= target; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= 20; j++) {
    dp[0][j] = 1;
  }
  for (int i = 1; i <= target; i++) {
    for (int j = 1; j <= N; j++) {
      // cout << "i,j : " <<i << " " << j << endl;
      dp[i][j] = 0;
      int k = 0;
      while (i - Coin[j] * k >= 0) {
        dp[i][j] += dp[i - Coin[j] * k][j - 1];
        k++;
      }
    }
  }

  cout << dp[target][N] << endl;
}
