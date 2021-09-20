#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

enum Status { EMPTY, TYPE1, TYPE2, TYPE3, TYPE4, TYPE5, WALL };

enum dir_type {
  UP,
  RIGHT,
  DOWN,
  LEFT,
  UPDOWN,
  RIGHTLEFT,
  UPRIGHT,
  RIGHTDOWN,
  DOWNLEFT,
  LEFTUP,
  URD,
  RDL,
  DLU,
  LUR,
  ALL
};

struct camera {
  int y;
  int x;
  int type;
  int dir;
};

int N, M;
int camera_size;
int answer;
int A[9][9];
bool checked[9][9];
vector<camera> cameras;

void input();
void solve();
void init_checked_array();
camera make_camera(int _y, int _x, int _type);
void dfs(int camera_index);
void make_checked_array();
void make_camera_true(int dir, int y, int x);
int count_checked();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

camera make_camera(int _y, int _x, int _type) {
  camera result;
  result.y = _y;
  result.x = _x;
  result.type = _type;
  return result;
}

void input() {
  camera_size = 0;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int temp;
      cin >> temp;
      if (temp != EMPTY && temp != WALL) {
        cameras.push_back(make_camera(i, j, temp));
        camera_size++;
      }

      A[i][j] = temp;
    }
  }
}

void solve() {
  answer = N * M;
  dfs(0);
  cout << answer;
}

void dfs(int camera_index) {
  if (camera_index == camera_size) {
    init_checked_array();
    make_checked_array();
    int counts = count_checked();
    if (counts < answer) {
      answer = counts;
    }
    return;
  }
  int now_type = cameras[camera_index].type;
  // cout << "y,x,type : " << cameras[camera_index].y << " " <<
  // cameras[camera_index].x << " " << cameras[camera_index].type << endl;

  switch (now_type) {
  case TYPE1:
    cameras[camera_index].dir = UP;
    dfs(camera_index + 1);

    cameras[camera_index].dir = RIGHT;
    dfs(camera_index + 1);

    cameras[camera_index].dir = DOWN;
    dfs(camera_index + 1);

    cameras[camera_index].dir = LEFT;
    dfs(camera_index + 1);
    break;
  case TYPE2:
    cameras[camera_index].dir = UPDOWN;
    dfs(camera_index + 1);

    cameras[camera_index].dir = RIGHTLEFT;
    dfs(camera_index + 1);
    break;
  case TYPE3:
    cameras[camera_index].dir = UPRIGHT;
    dfs(camera_index + 1);

    cameras[camera_index].dir = RIGHTDOWN;
    dfs(camera_index + 1);

    cameras[camera_index].dir = DOWNLEFT;
    dfs(camera_index + 1);

    cameras[camera_index].dir = LEFTUP;
    dfs(camera_index + 1);
    break;
  case TYPE4:
    cameras[camera_index].dir = URD;
    dfs(camera_index + 1);

    cameras[camera_index].dir = RDL;
    dfs(camera_index + 1);

    cameras[camera_index].dir = DLU;
    dfs(camera_index + 1);

    cameras[camera_index].dir = LUR;
    dfs(camera_index + 1);
    break;
  case TYPE5:
    cameras[camera_index].dir = ALL;
    dfs(camera_index + 1);
    break;

  default:
    cout << camera_index << " camera error!" << endl;
    break;
  }
}

void init_checked_array() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] == 0) {
        checked[i][j] = false;
      } else {
        checked[i][j] = true;
      }
    }
  }
}

void make_checked_array() {
  for (int i = 0; i < camera_size; i++) {
    int y = cameras[i].y;
    int x = cameras[i].x;
    int dir = cameras[i].dir;
    int type = cameras[i].type;

    checked[y][x] = true;

    switch (type) {
    case TYPE1:
      if (dir == UP) {
        make_camera_true(UP, y, x);
      } else if (dir == DOWN) {
        make_camera_true(DOWN, y, x);
      } else if (dir == RIGHT) {
        make_camera_true(RIGHT, y, x);
      } else {
        make_camera_true(LEFT, y, x);
      }
      break;

    case TYPE2:
      if (dir == UPDOWN) {
        make_camera_true(UP, y, x);
        make_camera_true(DOWN, y, x);
      } else {
        make_camera_true(RIGHT, y, x);
        make_camera_true(LEFT, y, x);
      }
      break;

    case TYPE3:
      if (dir == UPRIGHT) {
        make_camera_true(UP, y, x);
        make_camera_true(RIGHT, y, x);
      } else if (dir == RIGHTDOWN) {
        make_camera_true(DOWN, y, x);
        make_camera_true(RIGHT, y, x);
      } else if (dir == DOWNLEFT) {
        make_camera_true(DOWN, y, x);
        make_camera_true(LEFT, y, x);
      } else {
        make_camera_true(LEFT, y, x);
        make_camera_true(UP, y, x);
      }
      break;

    case TYPE4:
      if (dir == URD) {
        make_camera_true(UP, y, x);
        make_camera_true(RIGHT, y, x);
        make_camera_true(DOWN, y, x);
      } else if (dir == RDL) {
        make_camera_true(RIGHT, y, x);
        make_camera_true(DOWN, y, x);
        make_camera_true(LEFT, y, x);
      } else if (dir == DLU) {
        make_camera_true(DOWN, y, x);
        make_camera_true(LEFT, y, x);
        make_camera_true(UP, y, x);
      } else {
        make_camera_true(LEFT, y, x);
        make_camera_true(UP, y, x);
        make_camera_true(RIGHT, y, x);
      }
      break;

    case TYPE5:
      make_camera_true(UP, y, x);
      make_camera_true(RIGHT, y, x);
      make_camera_true(DOWN, y, x);
      make_camera_true(LEFT, y, x);
      break;

    default:
      break;
    }
  }
}

void make_camera_true(int dir, int y, int x) {
  switch (dir) {
  case UP:
    for (int i = 1;; i++) {
      if (y - i < 0 || A[y - i][x] == WALL) {
        break;
      }
      checked[y - i][x] = true;
    }
    break;
  case DOWN:
    for (int i = 1;; i++) {
      if (y + i >= N || A[y + i][x] == WALL) {
        break;
      }
      checked[y + i][x] = true;
    }
    break;
  case RIGHT:
    for (int i = 1;; i++) {
      if (x + i >= M || A[y][x + i] == WALL) {
        break;
      }
      checked[y][x + i] = true;
    }
    break;
  case LEFT:
    for (int i = 1;; i++) {
      if (x - i < 0 || A[y][x - i] == WALL) {
        break;
      }
      checked[y][x - i] = true;
    }
    break;

  default:
    break;
  }
}

int count_checked() {
  int counts = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!checked[i][j]) {
        counts++;
      }
    }
  }
  return counts;
}
