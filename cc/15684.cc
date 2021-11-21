#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

int N, M, H;
bool board[31][11] = {
    false,
};
bool isVisited[31][11] = {
    false,
};

void input();
void solve();
void dfs(int maxRow, int now, int y, int x);
bool isValidIndex(int y, int x) { return y >= 1 && y <= H && x >= 1 && x <= N; }
bool isAnswer();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> M >> H;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    board[a][b] = true;
  }
}

void solve() {
  for (int i = 0; i < 4; i++) {
    dfs(i, 0, 1, 1);
  }
  cout << "-1\n";
}

void dfs(int maxRow, int now, int y, int x) {
  if (maxRow == now) {
    if (isAnswer()) {
      cout << maxRow << endl;
      exit(0);
    }
    return;
  }
  if (y == H + 1) {
    return;
  }
  int nextX = x + 1;
  int nextY = y;
  if (nextX >= N) {
    nextX = 1;
    nextY++;
  }
  if (board[y][x]) {
    dfs(maxRow, now, nextY, nextX);
    return;
  }

  if (!(isValidIndex(y, x + 1) && board[y][x + 1]) &&
      !(isValidIndex(y, x - 1) && board[y][x - 1])) {
    board[y][x] = true;
    dfs(maxRow, now + 1, nextY, nextX);
  }
  board[y][x] = false;
  dfs(maxRow, now, nextY, nextX);
}

bool isAnswer() {
  for (int i = 1; i <= N; i++) {
    memset(isVisited, false, sizeof(isVisited));
    // i가 i에 도착하지 못했으면 false 반환
    int nowRow = 1;
    int nowCol = i;
    while (nowRow <= H) {
      if (nowCol == 1) {
        if (board[nowRow][nowCol] && !isVisited[nowRow][nowCol]) {
          isVisited[nowRow][nowCol] = true;
          nowCol++;
        } else {
          nowRow++;
        }
      } else if (nowCol == N) {
        if (board[nowRow][nowCol - 1] && !isVisited[nowRow][nowCol - 1]) {
          isVisited[nowRow][nowCol - 1] = true;
          nowCol--;
        } else {
          nowRow++;
        }
      } else {
        if (board[nowRow][nowCol] && !isVisited[nowRow][nowCol]) {
          isVisited[nowRow][nowCol] = true;
          nowCol++;
        } else if (board[nowRow][nowCol - 1] &&
                   !isVisited[nowRow][nowCol - 1]) {
          isVisited[nowRow][nowCol - 1] = true;
          nowCol--;
        } else {
          nowRow++;
        }
      }
    }
    if (nowCol != i) {
      return false;
    }
  }
  return true;
}
