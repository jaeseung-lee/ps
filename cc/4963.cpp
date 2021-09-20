#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int C, R;
int Board[50][50];
bool visited[50][50];
void solve();

int dir[8][2] = {{-1, 0}, {1, 0},  {0, 1},  {0, -1},
                 {1, 1},  {1, -1}, {-1, 1}, {-1, -1}};
bool is_valid_index(int y, int x);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}

void solve() {
  while (true) {
    cin >> C >> R;
    if (C == 0 && R == 0) {
      break;
    }

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cin >> Board[i][j];
        visited[i][j] = false;
      }
    }
    int count = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (Board[i][j] == 1 && !visited[i][j]) {
          queue<pair<int, int>> q;
          q.push(make_pair(i, j));
          visited[i][j] = true;
          count++;
          while (!q.empty()) {
            int now_y = q.front().first;
            int now_x = q.front().second;
            q.pop();
            for (int d = 0; d < 8; d++) {
              int next_y = now_y + dir[d][0];
              int next_x = now_x + dir[d][1];
              if (is_valid_index(next_y, next_x) && !visited[next_y][next_x] &&
                  Board[next_y][next_x] == 1) {
                q.push(make_pair(next_y, next_x));
                visited[next_y][next_x] = true;
              }
            }
          }
        }
      }
    }
    cout << count << endl;
  }
}

bool is_valid_index(int y, int x) { return y < R && y >= 0 && x < C && x >= 0; }
