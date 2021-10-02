#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int K, W, H;
int Board[200][200];
int visited[200][200][31];

void input();
void solve();
bool is_valid_index(int y, int x);
bool is_available(int y, int x, int k);

int h_d[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {1, -2},
                 {2, -1},  {-1, 2},  {1, 2},  {2, 1}};
int m_d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> K >> W >> H;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> Board[i][j];
    }
  }
}

void solve() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      for (int k = 0; k <= K; k++) {
        visited[i][j][k] = -1;
      }
    }
  }
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(0, 0), 0));
  visited[0][0][0] = 0;

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int k = q.front().second;
    int value = visited[y][x][k];
    q.pop();
    if (k < K) {
      for (int d = 0; d < 8; d++) {
        if (is_available(y + h_d[d][0], x + h_d[d][1], k + 1)) {
          // cout << "now :" << y+h_d[d][0] << " "<<x+h_d[d][1] << endl;
          q.push(make_pair(make_pair(y + h_d[d][0], x + h_d[d][1]), k + 1));
          visited[y + h_d[d][0]][x + h_d[d][1]][k + 1] = value + 1;
        }
      }
    }

    for (int d = 0; d < 4; d++) {
      if (is_available(y + m_d[d][0], x + m_d[d][1], k)) {
        q.push(make_pair(make_pair(y + m_d[d][0], x + m_d[d][1]), k));
        visited[y + m_d[d][0]][x + m_d[d][1]][k] = value + 1;
      }
    }
  }
  int answer = 40001;
  for (int i = 0; i <= K; i++) {
    if (visited[H - 1][W - 1][i] != -1 && answer > visited[H - 1][W - 1][i]) {
      answer = visited[H - 1][W - 1][i];
    }
  }
  if (answer != 40001) {
    cout << answer;
  } else {
    cout << "-1";
  }
}

bool is_valid_index(int y, int x) { return y >= 0 && y < H && x >= 0 && x < W; }
bool is_available(int y, int x, int k) {
  return is_valid_index(y, x) && visited[y][x][k] == -1 && Board[y][x] == 0;
}
