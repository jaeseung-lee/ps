#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'

using namespace std;

int R, C;
char board[51][51];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
bool visited[50][50];
int answer = 0;

void input();
void solve();
void clear_visited();
bool is_valid_index(int y, int x);

int main() {
  // ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> R >> C;
  getchar();
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      board[i][j] = getchar();
    }
    getchar();
  }
}

void solve() {
  for (int i = 0; i <= R; i++) {
    for (int j = 0; j <= C; j++) {
      if (board[i][j] == 'L') {
        //(y,x),distance
        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(make_pair(i, j), 0));
        clear_visited();
        visited[i][j] = true;
        while (!q.empty()) {
          int now_y = q.front().first.first;
          int now_x = q.front().first.second;
          int value = q.front().second;
          q.pop();
          for (int d_i = 0; d_i < 4; d_i++) {
            int next_y = dy[d_i] + now_y;
            int next_x = dx[d_i] + now_x;
            if (is_valid_index(next_y, next_x) &&
                board[next_y][next_x] == 'L' && !visited[next_y][next_x]) {
              q.push(make_pair(make_pair(next_y, next_x), value + 1));
              visited[next_y][next_x] = true;
            }
          }
          if (answer < value) {
            answer = value;
          }
        }
      }
    }
  }
  cout << answer;
}

void clear_visited() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      visited[i][j] = false;
    }
  }
}
bool is_valid_index(int y, int x) { return y < R && y >= 0 && x < C && x >= 0; }
