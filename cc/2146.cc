#include <iostream>
#include <queue>
using namespace std;

#define endl '\n'

int N;
int Board[100][100];
bool visited[100][100];
void input();
void solve();
bool is_valid_index(int y, int x) { return y < N && y >= 0 && x < N && x >= 0; }

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans = 100000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();
  cout << ans;
  return 0;
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> Board[i][j];
    }
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j] && Board[i][j] == 1) {
        //이 섬이 어디까지인지 큐에 넣음.
        queue<pair<int, int>> q;
        queue<pair<pair<int, int>, int>> w_q; // 여기다가는 가장자리 넣음
        visited[i][j] = true;
        q.push(make_pair(i, j));
        while (!q.empty()) {
          int now_y = q.front().first;
          int now_x = q.front().second;
          q.pop();
          for (int d = 0; d < 4; d++) {
            int next_y = now_y + dir[d][0];
            int next_x = now_x + dir[d][1];
            if (is_valid_index(next_y, next_x) && !visited[next_y][next_x]) {
              visited[next_y][next_x] = true;
              if (Board[next_y][next_x] == 1) {
                q.push(make_pair(next_y, next_x));
              } else {
                w_q.push(make_pair(make_pair(next_y, next_x), 1));
              }
            }
          }
        }

        bool is_found = false;

        // cout << "i,j : " << i << " " << j << endl;

        while (!w_q.empty()) {
          int now_y = w_q.front().first.first;
          int now_x = w_q.front().first.second;
          int value = w_q.front().second;
          // cout << "now_y : " << now_y << " now_x : " << now_x << endl;
          // cout << "value : " << value << endl;
          w_q.pop();
          for (int d = 0; d < 4; d++) {
            int next_y = now_y + dir[d][0];
            int next_x = now_x + dir[d][1];
            if (is_valid_index(next_y, next_x) && !visited[next_y][next_x]) {
              if (Board[next_y][next_x] == 0) {
                visited[next_y][next_x] = true;
                if (value + 1 < ans) {
                  w_q.push(make_pair(make_pair(next_y, next_x), value + 1));
                }
              } else {
                if (ans > value) {
                  ans = value;
                }
              }
            }
          }
        }
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
            if (Board[i][j] == 0) {
              visited[i][j] = false;
            }
          }
        }
      }
    }
  }
}
