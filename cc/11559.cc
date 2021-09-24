#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

char field[12][6];
bool visited[12][6];
int ans = 0;

void input();
void solve();

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(char type, int now_y, int now_x);
bool is_valid_index(int y, int x) {
  return y < 12 && y >= 0 && x >= 0 && x < 6;
}

queue<pair<int, int>> q;

int main() {
  // ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      field[i][j] = getchar();
    }
    getchar();
  }
}

void solve() {
  bool is_end = false;
  while (true && !is_end) {
    is_end = true;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        if (field[i][j] != '.' && !visited[i][j]) {
          visited[i][j] = true;
          q.push(make_pair(i, j));
          dfs(field[i][j], i, j);
          if (q.size() >= 4) {
            while (!q.empty()) {
              int y = q.front().first;
              int x = q.front().second;
              q.pop();
              field[y][x] = '.';
            }
            is_end = false;
          } else {
            while (!q.empty()) {
              q.pop();
            }
          }
        }
      }
    }
    if (!is_end) {
      ans++;
    }
    //아래로 떨어뜨리기
    for (int j = 0; j < 6; j++) {
      for (int i = 11; i >= 0; i--) {
        if (field[i][j] == '.') {
          continue;
        } else if (i < 11 && field[i + 1][j] == '.') {
          field[i + 1][j] = field[i][j];
          field[i][j] = '.';
          i = i + 2;
        }
      }
    }
  }
  cout << ans << endl;
}

void dfs(char type, int now_y, int now_x) {
  for (int d = 0; d < 4; d++) {
    int next_y = dir[d][0] + now_y;
    int next_x = dir[d][1] + now_x;
    if (is_valid_index(next_y, next_x) && field[next_y][next_x] == type &&
        !visited[next_y][next_x]) {
      q.push(make_pair(next_y, next_x));
      visited[next_y][next_x] = true;
      dfs(type, next_y, next_x);
    }
  }
}
