#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int ROW_MAX, COL_MAX;
vector<vector<int>> board;
int answer = 0;

void input();
void solve();
void block_1_4();
void block_2_3();
void block_2_2();
void block_3_2();
void block_4_1();

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  cout << answer;

  return 0;
}

void input() {
  cin >> ROW_MAX >> COL_MAX;
  for (int i = 0; i < ROW_MAX; i++) {
    vector<int> temp_row;
    for (int j = 0; j < COL_MAX; j++) {
      int temp;
      cin >> temp;
      temp_row.push_back(temp);
    }
    board.push_back(temp_row);
  }
}

void solve() {
  // 1*4짜리 확인
  block_1_4();

  // 2*3짜리 확인
  block_2_3();

  // 2*2짜리 확인
  block_2_2();

  // 3*2짜리 확인
  block_3_2();

  // 4*1짜리 확인
  block_4_1();
}

void block_1_4() {
  for (int i = 0; i < ROW_MAX - 3; i++) {
    for (int j = 0; j < COL_MAX; j++) {
      int temp =
          board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
      if (temp > answer) {
        answer = temp;
      }
    }
  }
}

void block_2_3() {
  for (int i = 0; i < ROW_MAX - 2; i++) {
    for (int j = 0; j < COL_MAX - 1; j++) {
      int temp =
          board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i][j + 1];
      if (temp > answer) {
        answer = temp;
      }
      temp =
          board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
      if (temp > answer) {
        answer = temp;
      }
      temp =
          board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
      if (temp > answer) {
        answer = temp;
      }

      temp = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] +
             board[i + 2][j + 1];
      if (temp > answer) {
        answer = temp;
      }
      temp = board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1] +
             board[i + 2][j + 1];
      if (temp > answer) {
        answer = temp;
      }
      temp = board[i + 2][j] + board[i][j + 1] + board[i + 1][j + 1] +
             board[i + 2][j + 1];
      if (temp > answer) {
        answer = temp;
      }

      temp = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] +
             board[i + 2][j + 1];
      if (temp > answer) {
        answer = temp;
      }
      temp = board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j] +
             board[i + 2][j];
      if (temp > answer) {
        answer = temp;
      }
    }
  }
}

void block_2_2() {
  for (int i = 0; i < ROW_MAX - 1; i++) {
    for (int j = 0; j < COL_MAX - 1; j++) {
      int temp =
          board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i][j + 1];
      if (temp > answer) {
        answer = temp;
      }
    }
  }
}

void block_3_2() {
  for (int i = 0; i < ROW_MAX - 1; i++) {
    for (int j = 0; j < COL_MAX - 2; j++) {
      int temp =
          board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j];
      if (temp > answer) {
        answer = temp;
      }
      temp =
          board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
      if (temp > answer) {
        answer = temp;
      }
      temp =
          board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
      if (temp > answer) {
        answer = temp;
      }

      temp = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] +
             board[i][j];
      if (temp > answer) {
        answer = temp;
      }

      temp = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] +
             board[i][j + 1];
      if (temp > answer) {
        answer = temp;
      }

      temp = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] +
             board[i][j + 2];
      if (temp > answer) {
        answer = temp;
      }

      temp = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] +
             board[i + 1][j + 2];
      if (temp > answer) {
        answer = temp;
      }
      temp = board[i][j + 2] + board[i][j + 1] + board[i + 1][j + 1] +
             board[i + 1][j];
      if (temp > answer) {
        answer = temp;
      }
    }
  }
}

void block_4_1() {
  for (int i = 0; i < ROW_MAX; i++) {
    for (int j = 0; j < COL_MAX - 3; j++) {
      int temp =
          board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
      if (temp > answer) {
        answer = temp;
      }
    }
  }
}
