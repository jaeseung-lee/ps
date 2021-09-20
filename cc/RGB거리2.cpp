#include <iostream>

#define endl '\n'

using namespace std;

int N;
int A[1001][3];
enum Color { RED, GREEN, BLUE };
int dp[3][1001][3];

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
    cin >> A[i][RED] >> A[i][GREEN] >> A[i][BLUE];
  }
}

void solve() {
  // boundary
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != j) {
        dp[i][0][j] = A[1][i] + A[2][j];
      }
    }
  }

  if (N != 2) {
    // RGB
    dp[RED][1][BLUE] = A[1][RED] + A[2][GREEN] + A[3][BLUE];
    // RBG
    dp[RED][1][GREEN] = A[1][RED] + A[2][BLUE] + A[3][GREEN];
    // BRG
    dp[BLUE][1][GREEN] = A[1][BLUE] + A[2][RED] + A[3][GREEN];
    // BGR
    dp[BLUE][1][RED] = A[1][BLUE] + A[2][GREEN] + A[3][RED];
    // GBR
    dp[GREEN][1][RED] = A[1][GREEN] + A[2][BLUE] + A[3][RED];
    // GRB
    dp[GREEN][1][BLUE] = A[1][GREEN] + A[2][RED] + A[3][BLUE];

    for (int length = 2; length <= N - 2; length++) {
      // RED to GREEN
      dp[RED][length][GREEN] = dp[RED][length - 1][BLUE];
      if (dp[RED][length][GREEN] >
          dp[RED][length - 2][GREEN] + A[length + 1][RED]) {
        dp[RED][length][GREEN] =
            dp[RED][length - 2][GREEN] + A[length + 1][RED];
      }
      if (dp[RED][length][GREEN] >
          dp[RED][length - 2][BLUE] + A[length + 1][RED]) {
        dp[RED][length][GREEN] = dp[RED][length - 2][BLUE] + A[length + 1][RED];
      }
      dp[RED][length][GREEN] += A[length + 2][GREEN];
      // cout << dp[RED][length][GREEN] << " ";

      // RED to BLUE
      dp[RED][length][BLUE] = dp[RED][length - 1][GREEN];
      if (dp[RED][length][BLUE] >
          dp[RED][length - 2][GREEN] + A[length + 1][RED]) {
        dp[RED][length][BLUE] = dp[RED][length - 2][GREEN] + A[length + 1][RED];
      }
      if (dp[RED][length][BLUE] >
          dp[RED][length - 2][BLUE] + A[length + 1][RED]) {
        dp[RED][length][BLUE] = dp[RED][length - 2][BLUE] + A[length + 1][RED];
      }
      dp[RED][length][BLUE] += A[length + 2][BLUE];
      // cout << dp[RED][length][BLUE] << " ";

      // GREEN to RED
      dp[GREEN][length][RED] = dp[GREEN][length - 1][BLUE];
      if (dp[GREEN][length][RED] >
          dp[GREEN][length - 2][RED] + A[length + 1][GREEN]) {
        dp[GREEN][length][RED] =
            dp[GREEN][length - 2][RED] + A[length + 1][GREEN];
      }
      if (dp[GREEN][length][RED] >
          dp[GREEN][length - 2][BLUE] + A[length + 1][GREEN]) {
        dp[GREEN][length][RED] =
            dp[GREEN][length - 2][BLUE] + A[length + 1][GREEN];
      }
      dp[GREEN][length][RED] += A[length + 2][RED];
      // cout << dp[GREEN][length][RED] << " ";

      // GREEN to BLUE
      dp[GREEN][length][BLUE] = dp[GREEN][length - 1][RED];
      if (dp[GREEN][length][BLUE] >
          dp[GREEN][length - 2][RED] + A[length + 1][GREEN]) {
        dp[GREEN][length][BLUE] =
            dp[GREEN][length - 2][RED] + A[length + 1][GREEN];
      }
      if (dp[GREEN][length][BLUE] >
          dp[GREEN][length - 2][BLUE] + A[length + 1][GREEN]) {
        dp[GREEN][length][BLUE] =
            dp[GREEN][length - 2][BLUE] + A[length + 1][GREEN];
      }
      dp[GREEN][length][BLUE] += A[length + 2][BLUE];
      // cout << dp[GREEN][length][BLUE] << " ";

      // BLUE to RED
      dp[BLUE][length][RED] = dp[BLUE][length - 1][GREEN];
      if (dp[BLUE][length][RED] >
          dp[BLUE][length - 2][GREEN] + A[length + 1][BLUE]) {
        dp[BLUE][length][RED] =
            dp[BLUE][length - 2][GREEN] + A[length + 1][BLUE];
      }
      if (dp[BLUE][length][RED] >
          dp[BLUE][length - 2][RED] + A[length + 1][BLUE]) {
        dp[BLUE][length][RED] = dp[BLUE][length - 2][RED] + A[length + 1][BLUE];
      }
      dp[BLUE][length][RED] += A[length + 2][RED];
      // cout << dp[BLUE][length][RED] << " ";

      // BLue to GREEN
      dp[BLUE][length][GREEN] = dp[BLUE][length - 1][RED];
      if (dp[BLUE][length][GREEN] >
          dp[BLUE][length - 2][GREEN] + A[length + 1][BLUE]) {
        dp[BLUE][length][GREEN] =
            dp[BLUE][length - 2][GREEN] + A[length + 1][BLUE];
      }
      if (dp[BLUE][length][GREEN] >
          dp[BLUE][length - 2][RED] + A[length + 1][BLUE]) {
        dp[BLUE][length][GREEN] =
            dp[BLUE][length - 2][RED] + A[length + 1][BLUE];
      }
      dp[BLUE][length][GREEN] += A[length + 2][GREEN];
      // cout << dp[BLUE][length][GREEN]  << " ";
      // cout << endl;
    }
  }

  int answer = dp[RED][N - 2][BLUE];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // cout << dp[i][N-2][j] << " ";
      if (i != j && answer > dp[i][N - 2][j]) {
        answer = dp[i][N - 2][j];
      }
    }
  }
  // cout << endl;
  cout << answer;
}
