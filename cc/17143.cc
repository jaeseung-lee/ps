#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

enum direction { UP = 1, DOWN = 2, RIGHT = 3, LEFT = 4 };

int R, C, M;

struct status {
  bool is_shark;
  int shark_index;
};

int ans = 0;

void input();
void solve();

status board[101][101];
status makeStatus(int shark_index) {
  status result;
  result.is_shark = true;
  result.shark_index = shark_index;
  return result;
}

status makeStatus() {
  status result;
  result.is_shark = false;
  result.shark_index = -1;
  return result;
}

struct sharkStatus {
  bool is_alive;
  int velocity;
  int dir;
  int size;
  int r;
  int c;
};

sharkStatus makeSharkStatus(int velocity, int dir, int size, int r, int c) {
  sharkStatus result;
  result.velocity = velocity;
  result.dir = dir;
  result.size = size;
  result.r = r;
  result.c = c;
  return result;
}

void makeSharkDead(sharkStatus& target) { target.is_alive = false; }
void moveShark(sharkStatus& target, int new_dir, int new_r, int new_c) {
  target.dir = new_dir;
  target.r = new_r;
  target.c = new_c;
}

vector<sharkStatus> sharkSpot;

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
      board[i][j] = makeStatus();
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> r >> c >> s >> d >> z;
    board[r][c] = makeStatus(sharkSpot.size());
    sharkSpot.push_back(makeSharkStatus(s, d, z, r, c));
  }
}

void solve() {
  for (int i = 1; i <= C; i++) {
    // 땅과 가장 가까운 상어 잡어먹기
    for (int j = 1; j <= R; j++) {
      if (board[j][i].is_shark) {
        ans += sharkSpot[board[i][j].shark_index].size;
        board[j][i] = makeStatus();
        sharkSpot[board[j][i].shark_index].is_alive = false;
        break;
      }
    }

    // 상어들이 움직임
    // 일단 상어들이 움직인 위치를 sharkSpot에 저장시키고
    // board는 비워둠
    for (auto shark : sharkSpot) {
      if (shark.is_alive) {
        switch (shark.dir) {
          case UP:

            break;
          case DOWN:

            break;

          case LEFT:

            break;

          case RIGHT:
            if ((shark.r + shark.velocity) % (2 * R - 2) <= R) {
              shark.r = (shark.r + shark.velocity) % (2 * R - 2);
            } else {
              shark.r = 2 * R - (shark.r + shark.velocity) % (2 * R - 2);
            }
            break;

          default:
            break;
        }
      }
    }

    // 상어들을 sharkSpot을 통하여 board에 채워넣는데, 이미 채워져있으면 더 큰
    // 거로 채워넣는다.
    for (int shark_index = 0; shark_index < sharkSpot.size(); shark_index++) {
      if (sharkSpot[shark_index].is_alive) {
        // 비어있는 칸이면 그냥 집어넣는다.
        if (!board[sharkSpot[shark_index].r][sharkSpot[shark_index].c]
                 .is_shark) {
          board[sharkSpot[shark_index].r][sharkSpot[shark_index].c].is_shark =
              true;
          board[sharkSpot[shark_index].r][sharkSpot[shark_index].c]
              .shark_index = shark_index;
        } else {
          // 비어있지 않으면 더 큰 걸 집어넣고, 작은 건 dead로 바꾼다.
          // board에 있는 상어가 더 크다면, sharkSpot 상어를 죽임
          if (sharkSpot[board[sharkSpot[shark_index].r]
                             [sharkSpot[shark_index].c]
                                 .shark_index]
                  .size > sharkSpot[shark_index].size) {
            sharkSpot[shark_index].is_alive = false;
          } else {
            // 들어올 상어가 더 크다면 기존의 상어를 죽이고, 그 board의 index
            // 정보를 갱신
            sharkSpot[board[sharkSpot[shark_index].r][sharkSpot[shark_index].c]
                          .shark_index]
                .is_alive = false;
            board[sharkSpot[shark_index].r][sharkSpot[shark_index].c]
                .shark_index = shark_index;
          }
        }
      }
    }
  }
}
