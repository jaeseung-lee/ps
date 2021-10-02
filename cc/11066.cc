#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define INF 100000001

int T, K;
int file[500];
int dp[500][500];
int sum[500][500];

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}

void solve() {
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> K;
    for (int i = 0; i < K; i++) {
      cin >> file[i];
    }
    for (int i = 0; i < K; i++) {
      dp[i][i] = 0;
    }
    for (int i = 0; i < K; i++) {
      for (int j = i; j < K; j++) {
        sum[i][j] = 0;
        for (int k = i; k <= j; k++) {
          sum[i][j] += file[k];
        }
      }
    }
    /*
    cout << endl;
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < K; j++) {
        cout << sum[i][j] << '\t';
      }
      cout << endl;
    }
    */

    for (int i = 1; i < K; i++) {
      for (int j = 0; i + j < K; j++) {
        dp[j][j + i] = INF;
        for (int k = j; k < j + i; k++) {
          if (dp[j][j + i] > dp[j][k] + dp[k + 1][j + i]) {
            dp[j][j + i] = dp[j][k] + dp[k + 1][j + i];
          }
        }
        dp[j][j + i] += sum[j][j + i];
      }
    }
    /*
        cout << endl;
        for (int i = 0; i < K; i++) {
          for (int j = 0; j < K; j++) {
            cout << dp[i][j] << '\t';
          }
          cout << endl;
        }
    */

    cout << dp[0][K - 1] << endl;
  }
}
