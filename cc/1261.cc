#include <deque>
#include <iostream>

using namespace std;

int M, N;
char Board[100][100];
int Broke[100][100];

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
  cin >> M >> N;
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
      Broke[i][j] = -1;
    }
  }
  deque<pair<pair<int, int>, int>> dq;
  dq.push_back(make_pair(make_pair(0, 0), 0));
  Broke[0][0] = 0;
  while (!dq.empty()) {
    int now_y = dq.front().first.first;
    int now_x = dq.front().first.second;
    int value = dq.front().second;
    dq.pop_front();
    if (now_y == N - 1 && now_x == M - 1) {
      cout << value << endl;
      break;
    }
    for (int d = 0; d < 4; d++) {
      int next_y = now_y + dir[d][0];
      int next_x = now_x + dir[d][1];
      if (is_valid_index(next_y, next_x)) {
        if (Board[next_y][next_x] == '0') {
          if (Broke[next_y][next_x] == -1) {
            Broke[next_y][next_x] = value;
            dq.push_front(make_pair(make_pair(next_y, next_x), value));
          } else if (Broke[next_y][next_x] > value) {
            Broke[next_y][next_x] = value;
            dq.push_front(make_pair(make_pair(next_y, next_x), value));
          } else {
            continue;
          }
        } else {
          if (Broke[next_y][next_x] == -1) {
            Broke[next_y][next_x] = value + 1;
            dq.push_back(make_pair(make_pair(next_y, next_x), value + 1));
          } else if (Broke[next_y][next_x] > (value + 1)) {
            Broke[next_y][next_x] = value + 1;
            dq.push_back(make_pair(make_pair(next_y, next_x), value + 1));
          } else {
            continue;
          }
        }
      }
    }
  }
}

bool is_valid_index(int y, int x) { return y < N && y >= 0 && x < M && x >= 0; }
