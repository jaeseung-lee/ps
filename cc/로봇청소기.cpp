#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

enum Direction { NORTH, EAST, SOUTH, WEST };

enum BoardStatus { UNCLEAN, WALL, CLEAN };

int COL_MAX;
int ROW_MAX;
int START_X;
int START_Y;
int INIT_DIRECTION;
vector<vector<int>> board;
int answer = 1;

class Robot {
private:
  int pos_x;
  int pos_y;
  int direction;

public:
  Robot(int start_x, int start_y, int init_direction);
  void Move(int target_direction);
  bool CheckNextDirection();
  int BackDirection(int target_direction); // 현재 방향의 반대 방향 반환
  bool IsStatus(int direction,
                int target_status); // 그 방향으로 한 칸 가면 벽인지 반환
  int NextDirection(int now_direction);
  void Display();
};

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  cout << answer;
  return 0;
}

Robot::Robot(int start_x, int start_y, int init_direction) {
  pos_x = start_x;
  pos_y = start_y;
  direction = init_direction;
}

// 0 -> 3 -> 2 -> 1 -> 0
int Robot::NextDirection(int now_direction) {
  switch (now_direction) {
  case NORTH:
    return WEST;
    break;
  case WEST:
    return SOUTH;
    break;
  case SOUTH:
    return EAST;
    break;
  case EAST:
    return NORTH;
    break;
  }
}

bool Robot::CheckNextDirection() {
  // << "pos x : " << pos_x << " pos_y : " << pos_y << endl;
  // cout << "current direction : " << direction << endl;
  int new_direction = NextDirection(direction);
  // cout << "init new direction " << new_direction << endl;
  for (int i = 0; i < 4; i++) {
    if (IsStatus(new_direction, UNCLEAN)) {
      Move(new_direction);
      board[pos_y][pos_x] = CLEAN;
      answer++;
      // cout << "Now Direction : " << new_direction << endl;
      direction = new_direction;
      return true;
    } else {
      new_direction = NextDirection(new_direction);
    }
  }

  int back_direction = BackDirection(direction);
  // cout << "back_direction : " << back_direction << endl;
  // 뒤로 한 칸 가려는 곳이 벽이 아니라면
  if (!IsStatus(back_direction, WALL)) {
    Move(back_direction);
    return true;
  }
  // 뒤로 한 칸 가려는 곳이 벽이라면
  else {
    return false;
  }
}

int Robot::BackDirection(int target_direction) {
  switch (target_direction) {
  case NORTH:
    return SOUTH;
    break;
  case WEST:
    return EAST;
    break;
  case SOUTH:
    return NORTH;
    break;
  case EAST:
    return WEST;
    break;
  }
}

bool Robot::IsStatus(int target_direction, int target_status) {
  switch (target_direction) {
  case NORTH:
    if (board[pos_y - 1][pos_x] == target_status) {
      return true;
    } else {
      return false;
    }
    break;
  case EAST:
    if (board[pos_y][pos_x + 1] == target_status) {
      return true;
    } else {
      return false;
    }
    break;

  case SOUTH:
    if (board[pos_y + 1][pos_x] == target_status) {
      return true;
    } else {
      return false;
    }
    break;

  case WEST:
    if (board[pos_y][pos_x - 1] == target_status) {
      return true;
    } else {
      return false;
    }
    break;
  }
}

void Robot::Move(int target_direction) {
  switch (target_direction) {
  case NORTH:
    pos_y--;
    break;
  case WEST:
    pos_x--;
    break;
  case SOUTH:
    pos_y++;
    break;
  case EAST:
    pos_x++;
    break;
  }
}

void input() {
  cin >> ROW_MAX >> COL_MAX >> START_Y >> START_X >> INIT_DIRECTION;
  for (int i = 0; i < ROW_MAX; i++) {
    vector<int> temp;
    for (int j = 0; j < COL_MAX; j++) {
      int board_status;
      cin >> board_status;
      temp.push_back(board_status);
    }
    board.push_back(temp);
  }
}

void solve() {
  Robot robot(START_X, START_Y, INIT_DIRECTION);
  board[START_Y][START_X] = CLEAN;
  while (true) {
    // robot.Display();
    if (!robot.CheckNextDirection()) {
      break;
    }
  }
}

void Robot::Display() {
  for (auto row : board) {
    for (auto element : row) {
      cout << element << " ";
    }
    cout << endl;
  }
}
