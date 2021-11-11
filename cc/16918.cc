#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

int R, C, N;
char board[200][200];
char next_board[200][200];

void input();
void solve();

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool is_valid_index(int y, int x) { return y >= 0 && y < R && x >= 0 && x < C; }

int main() {
  // ios::sync_with_stdio(false);
  input();
  solve();

  return 0;
}

void input() {
  cin >> R >> C >> N;
  getchar();
  memset(next_board, '.', sizeof(next_board));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      board[i][j] = getchar();
    }
    getchar();
  }
}

void solve() {
  if (N % 2 == 0) {
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cout << "O";
      }
      cout << endl;
    }
    return;
  }

  for (int n = 1; n < N; n = n + 2) {
    memset(next_board, 'O', sizeof(next_board));
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (board[i][j] == 'O') {
          next_board[i][j] = '.';
          for (int d = 0; d < 4; d++) {
            if (is_valid_index(i + dir[d][0], j + dir[d][1])) {
              next_board[i + dir[d][0]][j + dir[d][1]] = '.';
            }
          }
        }
      }
    }
    memcpy(board, next_board, sizeof(next_board));
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
}