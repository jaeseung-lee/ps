#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
int cleaner_y;
int board[50][50];
int temp_board[50][50];
vector<pair<int, int>> up_cleaner_path;
vector<pair<int, int>> down_cleaner_path;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

void input();
void solve();
bool is_valid_index(int y, int x);
void fill_up_cleaner_path();
void fill_down_cleaner_path();
void init_temp_board();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> R >> C >> T;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];
      if (board[i][j] == -1) {
        cleaner_y = i;
      }
    }
  }
}

void solve() {
  // path 채우기
  fill_down_cleaner_path();
  fill_up_cleaner_path();

  //시작

  for (int time = 0; time < T; time++) {
    //미세먼지 확산
    init_temp_board();
    for (int row = 0; row < R; row++) {
      for (int col = 0; col < C; col++) {
        if (board[row][col] > 0) {
          for (int dir = 0; dir < 4; dir++) {
            if (is_valid_index(row + dy[dir], col + dx[dir]) &&
                board[row + dy[dir]][col + dx[dir]] != -1) {
              temp_board[row + dy[dir]][col + dx[dir]] += board[row][col] / 5;
              temp_board[row][col] -= board[row][col] / 5;
            }
          }
        }
      }
    }
    for (int row = 0; row < R; row++) {
      for (int col = 0; col < C; col++) {
        board[row][col] += temp_board[row][col];
      }
    }

    //공기청정기
    for (int i = down_cleaner_path.size() - 1; i >= 1; i--) {
      board[down_cleaner_path[i].first][down_cleaner_path[i].second] =
          board[down_cleaner_path[i - 1].first]
               [down_cleaner_path[i - 1].second];
    }
    board[down_cleaner_path[0].first][down_cleaner_path[0].second] = 0;

    for (int i = up_cleaner_path.size() - 1; i >= 1; i--) {
      board[up_cleaner_path[i].first][up_cleaner_path[i].second] =
          board[up_cleaner_path[i - 1].first][up_cleaner_path[i - 1].second];
    }
    board[up_cleaner_path[0].first][up_cleaner_path[0].second] = 0;
  }

  int answer = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (board[i][j] > 0) {
        answer += board[i][j];
      }
    }
  }
  cout << answer << endl;
}

bool is_valid_index(int y, int x) { return y < R && y >= 0 && x < C && x >= 0; }

void fill_up_cleaner_path() {
  for (int i = 1; i < C; i++) {
    up_cleaner_path.push_back(make_pair(cleaner_y, i));
  }
  for (int i = cleaner_y - 1; i >= 0; i--) {
    up_cleaner_path.push_back(make_pair(i, C - 1));
  }
  for (int i = C - 2; i >= 0; i--) {
    up_cleaner_path.push_back(make_pair(0, i));
  }
  for (int i = 1; i < cleaner_y; i++) {
    up_cleaner_path.push_back(make_pair(i, 0));
  }
}
void fill_down_cleaner_path() {
  for (int i = 1; i < C; i++) {
    down_cleaner_path.push_back(make_pair(cleaner_y, i));
  }
  for (int i = cleaner_y + 1; i < R; i++) {
    down_cleaner_path.push_back(make_pair(i, C - 1));
  }
  for (int i = C - 2; i >= 0; i--) {
    down_cleaner_path.push_back(make_pair(R - 1, i));
  }
  for (int i = R - 2; i > cleaner_y; i--) {
    down_cleaner_path.push_back(make_pair(i, 0));
  }
  cleaner_y--;
}

void init_temp_board() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      temp_board[i][j] = 0;
    }
  }
}
