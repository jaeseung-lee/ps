#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int N, M;
char Board[50][50];
int visited[50][50];

void input();
void solve();
bool is_valid_index(int y, int x);

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
  // ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> M;
  getchar();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      Board[i][j] = getchar();
    }
    getchar();
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visited[i][j] = -1;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j] == -1) {
        queue<pair<int, int>> q;
        visited[i][j] = 1;
        q.push(make_pair(i, j));
        while (!q.empty()) {
          int now_y = q.front().first;
          int now_x = q.front().second;
          int value = visited[now_y][now_x];
          q.pop();
          for (int d = 0; d < 4; d++) {
            int next_y = now_y + dir[d][0];
            int next_x = now_x + dir[d][1];
            if (is_valid_index(next_y, next_x) &&
                (Board[now_y][now_x] == Board[next_y][next_x])) {
              if ((value - 1) !=
                  visited[next_y][next_x]) {  //바로 전꺼가 아니고
                if (visited[next_y][next_x] == -1) {
                  visited[next_y][next_x] = value + 1;
                  q.push(make_pair(next_y, next_x));
                } else {
                  cout << "Yes" << endl;
                  exit(0);
                }
              }
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
}

bool is_valid_index(int y, int x) { return y < N && y >= 0 && x < M && x >= 0; }
