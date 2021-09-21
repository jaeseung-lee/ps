#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
int N, M;
int Board[300][300];
int temp[300][300];
bool visited[300][300];

void input();
void solve();
bool is_valid_index(int y, int x) { return y < N && y >= 0 && x < M && x >= 0; }
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> Board[i][j];
    }
  }
}

void solve() {
  int answer = 1;
  while (true) {
    memset(temp, 0, sizeof(temp));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (Board[i][j] != 0) {
          int cnt = 0;
          for (int d = 0; d < 4; d++) {
            int next_y = i + dir[d][0];
            int next_x = j + dir[d][1];
            if (is_valid_index(next_y, next_x) && Board[next_y][next_x] == 0) {
              cnt++;
            }
            temp[i][j] = cnt;
          }
        }
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (Board[i][j] != 0) {
          Board[i][j] -= temp[i][j];
          if (Board[i][j] < 0) {
            Board[i][j] = 0;
          }
        }
      }
    }

    queue<pair<int, int>> q;
    bool is_found = false;
    for (int i = 0; i < N && !is_found; i++) {
      for (int j = 0; j < M && !is_found; j++) {
        if (Board[i][j] != 0 && !visited[i][j]) {
          is_found = true;
          q.push(make_pair(i, j));
          visited[i][j] = true;
          while (!q.empty()) {
            int now_y = q.front().first;
            int now_x = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
              int next_y = now_y + dir[d][0];
              int next_x = now_x + dir[d][1];
              if (is_valid_index(next_y, next_x) &&
                  Board[next_y][next_x] != 0 && !visited[next_y][next_x]) {
                q.push(make_pair(next_y, next_x));
                visited[next_y][next_x] = true;
              }
            }
          }
        }
      }
    }
    if (!is_found) {
      cout << "0" << endl;
      exit(0);
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (Board[i][j] != 0 && !visited[i][j]) {
          cout << answer << endl;
          exit(0);
        }
      }
    }
    answer++;
  }
}
