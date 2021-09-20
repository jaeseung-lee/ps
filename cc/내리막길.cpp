#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'

using namespace std;

int N, M;
int Board[500][500];
int dp[500][500];
int answer = 0;

void input();
void solve();
void search(int, int);
bool visited[500][500];
bool is_valid_index(int now_y, int now_x);
bool is_lower_index(int value, int now_y, int now_x);

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> Board[i][j];
    }
  }
}

void solve() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      visited[i][j] = false;
      dp[i][j] = -1;
    }
  }

  queue<pair<int, int>> zero_indice;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      bool is_zero = true;
      for (int d = 0; d < 4; d++) {
        if (!is_valid_index(i + dy[d], j + dx[d])) {
          continue;
        } else if (is_lower_index(Board[i][j], i + dy[d], j + dx[d]) ||
                   Board[i][j] == Board[i + dy[d]][j + dx[d]]) {
          continue;
        } else {
          is_zero = false;
          break;
        }
      }
      if (is_zero) {
        dp[i][j] = 0;
        zero_indice.push(make_pair(i, j));
      }
    }
  }

  if (!zero_indice.empty() && zero_indice.front().first == 0 &&
      zero_indice.front().second == 0) {
    dp[0][0] = -1;
    zero_indice.pop();
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  while (!zero_indice.empty()) {
    int i = zero_indice.front().first;
    int j = zero_indice.front().second;
    zero_indice.pop();
    cout << "i, j :" << i << " " << j << endl;
    for (int d = 0; d < 4; d++) {
      int y = dy[d] + i;
      int x = dx[d] + j;
      if (!is_valid_index(y, x)) {
        continue;
      }
      bool is_zero = true;
      cout << "y,x : " << y << " " << x << endl;
      for (int dd = 0; dd < 4; dd++) {
        cout << "y+dy[dd],x+dx[dd] : " << y + dy[dd] << " " << x + dx[dd]
             << endl;
        if (!is_valid_index(y + dy[dd], x + dx[dd])) {
          cout << "one\n";
          continue;
        } else if (is_lower_index(Board[y][x], y + dy[dd], x + dx[dd]) ||
                   Board[y][x] == Board[y + dy[dd]][x + dx[dd]]) {
          cout << "two\n";
          continue;
        } else if (dp[y + dy[dd]][x + dx[dd]] == 0) {
          cout << "three\n";
          continue;
        } else {
          cout << "four\n";
          is_zero = false;
          break;
        }
      }
      if (is_zero && dp[y][x] != 0) {
        zero_indice.push(make_pair(y, x));
        dp[y][x] = 0;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  dp[0][0] = 1;
  while (!q.empty()) {
    int now_y = q.front().first;
    int now_x = q.front().second;
    q.pop();
    if (dp[now_y][now_x] != -1) {
      continue;
    }
    for (int d = 0; d < 4; d++) {
      if (is_valid_index(now_y + dy[d], now_x + dx[d]) &&
          is_lower_index(Board[now_y][now_x], now_y + dy[d], now_x + dx[d])) {
        int y = now_y + dy[d];
        int x = now_x + dx[d];
        int value = 0;
        bool is_in_queue = true;
        for (int dd = 0; dd < 4; dd++) {
          if (!is_valid_index(y + dy[dd], x + dx[dd])) {
            continue;
          }
          if (is_lower_index(Board[y + dy[dd]][x + dx[dd]], y, x)) {
            if (dp[y + dy[dd]][x + dx[dd]] == -1) {
              is_in_queue = false;
              break;
            } else {
              value += dp[y + dy[dd]][x + dx[dd]];
            }
          }
        }
        if (is_in_queue) {
          q.push(make_pair(y, x));
          dp[y][x] = value;
        }
      }
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  // search(0,0);

  cout << answer;
}

void search(int now_y, int now_x) {
  if (now_y == M - 1 && now_x == N - 1) {
    answer++;
    return;
  }

  visited[now_y][now_x] = true;
  for (int d = 0; d < 4; d++) {
    if (is_valid_index(now_y + dy[d], now_x + dx[d]) &&
        !visited[now_y + dy[d]][now_x + dx[d]] &&
        is_lower_index(Board[now_y][now_x], now_y + dy[d], now_x + dx[d])) {
      search(now_y + dy[d], now_x + dx[d]);
    }
  }
  visited[now_y][now_x] = false;
}

bool is_valid_index(int now_y, int now_x) {
  return now_y >= 0 && now_y < M && now_x >= 0 && now_x < N;
}
bool is_lower_index(int value, int now_y, int now_x) {
  return value > Board[now_y][now_x];
}
