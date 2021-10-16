#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

char Board[11][11];
char TempBoard[11][11];
int ans = 101;

void input();
void solve();
void click(int y, int x);
void change_target(int y, int x);
bool is_valid_index(int y, int x);

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void first_row(int now_index, int clicked);

int main() {
  // ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      Board[i][j] = getchar();
    }
    getchar();
  }
}

void click(int y, int x) {
  change_target(y, x);
  for (int d = 0; d < 4; d++) {
    if (is_valid_index(y + dir[d][0], x + dir[d][1])) {
      change_target(y + dir[d][0], x + dir[d][1]);
    }
  }
}

void change_target(int y, int x) {
  if (Board[y][x] == '#') {
    Board[y][x] = 'O';
  } else {
    Board[y][x] = '#';
  }
}

void solve() {
  first_row(1, 0);
  if (ans == 101) {
    cout << "-1";
  } else {
    cout << ans;
  }
}

void first_row(int now_index, int clicked) {
  if (now_index > 10) {
    memcpy(TempBoard, Board, sizeof(Board));
    int temp_ans = clicked;
    for (int i = 2; i <= 10; i++) {
      for (int j = 1; j <= 10; j++) {
        if (Board[i - 1][j] == 'O') {
          click(i, j);
          temp_ans++;
        }
      }
    }
    bool is_answer = true;
    for (int j = 1; j <= 10; j++) {
      if (Board[10][j] == 'O') {
        is_answer = false;
        break;
      }
    }
    if (is_answer && (ans > temp_ans)) {
      ans = temp_ans;
    }
    memcpy(Board, TempBoard, sizeof(TempBoard));
    return;
  }
  first_row(now_index + 1, clicked);
  click(1, now_index);
  first_row(now_index + 1, clicked + 1);
  click(1, now_index);
}

bool is_valid_index(int y, int x) {
  return y <= 10 && y >= 1 && x <= 10 && x >= 1;
}
