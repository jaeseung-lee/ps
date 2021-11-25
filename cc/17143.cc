#include <iostream>

using namespace std;

#define endl '\n'

enum direction { UP = 1, DOWN = 2, RIGHT = 3, LEFT = 4 };

int R, C, M;

struct status {
  bool isShark;
  int velocity;
  int dir;
  int size;
};

int ans = 0;

void input();
void solve();

status board[101][101];
status make_status(int velocity, int dir, int size) {
  status result;
  result.velocity = velocity;
  result.dir = dir;
  result.size = size;
  result.isShark = true;
  return result;
}

status make_status() {
  status result;
  result.velocity = 0;
  result.isShark = false;
  result.dir = -1;
  result.size = 0;
  return result;
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
  cin >> R >> C >> M;
  int r, c, s, d, z;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      board[i][j] = make_status();
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> r >> c >> s >> d >> z;
    board[r][c] = make_status(s, d, z);
  }
}

void solve() {
  for (int i = 1; i <= C; i++) {
    // 땅과 가장 가까운 상어 잡어먹기
    for (int j = 1; j <= R; j++) {
      if (board[j][i].isShark) {
        ans += board[j][i].size;
        board[j][i] = make_status();
        break;
      }
    }

    // 상어들이 움직임
    // 상어 id도 주자.
  }
}
