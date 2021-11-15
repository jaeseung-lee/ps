#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int N;
int board[100][100];
int ans = 0;
bool is_visited[100][100];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void input();
void solve();
bool isValidIndex(int y, int x) { return y < N && y >= 0 && x >= 0 && x < N; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {
  for (int height = 0; height <= 100; height++) {
    memset(is_visited, false, sizeof(is_visited));
    int now = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!is_visited[i][j] && board[i][j] > height) {
          queue<pair<int, int>> q;
          now++;
          is_visited[i][j] = true;
          q.push(make_pair(i, j));
          while (!q.empty()) {
            int now_y = q.front().first;
            int now_x = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
              int next_y = now_y + dir[d][0];
              int next_x = now_x + dir[d][1];
              if (isValidIndex(next_y, next_x) && !is_visited[next_y][next_x] &&
                  board[next_y][next_x] > height) {
                q.push(make_pair(next_y, next_x));
                is_visited[next_y][next_x] = true;
              }
            }
          }
        }
      }
    }
    if (now > ans) {
      ans = now;
    }
  }
  cout << ans;
}
