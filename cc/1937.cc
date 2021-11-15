#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'
int board[500][500];
int dp[500][500];
int N;
int ans = 1;

void input();
void solve();
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isValidIndex(int y, int x) { return y >= 0 && y < N && x >= 0 && x < N; }
int dfs(int y, int x);

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
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (dp[i][j] == -1) {
        dfs(i, j);
      }
    }
  }
  cout << ans << endl;
}

int dfs(int y, int x) {
  if (dp[y][x] != -1) {
    return dp[y][x];
  } else {
    dp[y][x] = 1;
  }
  for (int d = 0; d < 4; d++) {
    int next_y = y + dir[d][0];
    int next_x = x + dir[d][1];
    if (isValidIndex(next_y, next_x) && board[y][x] < board[next_y][next_x]) {
      dp[y][x] = max(dp[y][x], 1 + dfs(next_y, next_x));
      if (ans < dp[y][x]) {
        ans = dp[y][x];
      }
    }
  }
  return dp[y][x];
}
