#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int T, K;
int file[500];
int dp[500][500];

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
    // boundary
    for (int i = 0; i < K; i++) {
      dp[i][i] = file[i];
    }
    for (int i = 0; i < K - 1; i++) {
      dp[i][i + 1] = file[i] + file[i + 1];
    }

    for (int i = 2; i < K; i++) {
      for (int j = 0; j + i < K; j++) {
        if (dp[j][j + i - 1] < dp[j + 1][j + i]) {
          dp[j][j + i] = 2 * dp[j][j + i - 1] + file[j];
        } else {
          dp[j][j + i] = 2 * dp[j + 1][j + i] + file[j + i];
        }
      }
    }

    for (int i = 0; i < K; i++) {
      for (int j = 0; j < K; j++) {
        cout << dp[i][j] << '\t';
      }
      cout << endl;
    }
    cout << dp[0][K - 1] << endl;
  }
}
