#include <iostream>
#include <vector>

using namespace std;

enum Color { R, G, B };

int N;
int A[1001][3];
int dp[1001][3];

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
    for (int j = 0; j < 3; j++) {
      cin >> A[i][j];
    }
  }
}

void solve() {
  // boundary
  dp[1][0] = A[1][0];
  dp[1][1] = A[1][1];
  dp[1][2] = A[1][2];

  for (int i = 2; i <= N; i++) {
    if (dp[i - 1][G] > dp[i - 1][B]) {
      dp[i][R] = dp[i - 1][B] + A[i][R];
    } else {
      dp[i][R] = dp[i - 1][G] + A[i][R];
    }

    if (dp[i - 1][R] > dp[i - 1][B]) {
      dp[i][G] = dp[i - 1][B] + A[i][G];
    } else {
      dp[i][G] = dp[i - 1][R] + A[i][G];
    }

    if (dp[i - 1][G] > dp[i - 1][R]) {
      dp[i][B] = dp[i - 1][R] + A[i][B];
    } else {
      dp[i][B] = dp[i - 1][G] + A[i][B];
    }
  }

  int answer = dp[N][R];
  if (answer > dp[N][G]) {
    answer = dp[N][G];
  }
  if (answer > dp[N][B]) {
    answer = dp[N][B];
  }
  cout << answer;
}
