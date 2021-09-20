#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int n, m;
char A[1001][1001];
int dp[1001][1001];

void input();
void solve();

int main() {
  // ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> n >> m;
  getchar();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      A[i][j] = getchar();
    }
    getchar();
  }
}

void solve() {
  int answer = 0;
  // boundary
  for (int i = 1; i <= n; i++) {
    if (A[i][1] == '0') {
      dp[i][1] = 0;
    } else {
      dp[i][1] = 1;
      answer = 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (A[1][i] == '0') {
      dp[1][i] = 0;
    } else {
      dp[1][i] = 1;
      answer = 1;
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      if (A[i][j] == '0') {
        dp[i][j] = 0;
      } else {
        dp[i][j] = dp[i - 1][j - 1];
        if (dp[i][j] > dp[i - 1][j]) {
          dp[i][j] = dp[i - 1][j];
        }
        if (dp[i][j] > dp[i][j - 1]) {
          dp[i][j] = dp[i][j - 1];
        }
        dp[i][j]++;
        if (answer < dp[i][j]) {
          answer = dp[i][j];
        }
      }
    }
  }

  cout << answer * answer;
}
