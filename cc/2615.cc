#include <cstring>
#include <iostream>
using namespace std;

#define endl '\n'

enum Color { EMPTY, BLACK, WHITE };

int board[20][20];
bool isVisited[20][20];

void input();
void solve();

void dfs(int y, int x, int d, int color, int how_many);

int dir[4][2] = {{1, 1}, {0, 1}, {1, 0}, {1, -1}};
bool isValidIndex(int y, int x) {
  return y <= 19 && y >= 1 && x <= 19 && x >= 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j <= 19; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {
  for (int d = 0; d < 4; d++) {
    memset(isVisited, false, sizeof(isVisited));
    for (int i = 1; i <= 19; i++) {
      for (int j = 1; j <= 19; j++) {
        if (board[i][j] != EMPTY) {
          if (!isVisited[i][j]) {
            dfs(i, j, d, board[i][j], 1);
          }
        }
      }
    }
  }

  cout << "0" << endl;
}

void dfs(int y, int x, int d, int color, int how_many) {
  int next_y = y + dir[d][0];
  int next_x = x + dir[d][1];
  if (how_many == 5 &&
      ((isValidIndex(next_y, next_x) && color != board[next_y][next_x]) ||
       !isValidIndex(next_y, next_x))) {
    cout << color << endl;
    if (dir[d][1] >= 0) {
      cout << y - 4 * dir[d][0] << " " << x - 4 * dir[d][1] << endl;
    } else {
      cout << y << " " << x << endl;
    }
    exit(0);
  }
  if (isValidIndex(next_y, next_x) && board[next_y][next_x] == color) {
    dfs(next_y, next_x, d, color, how_many + 1);
    isVisited[next_y][next_x] = true;
  }
  return;
}
