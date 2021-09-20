#include <iostream>

using namespace std;

#define endl '\n'

int N, M;
int Board[5][5];
int answer = 0;
bool visited[5][5];

void input();
void solve();
void dfs(int y, int x, int value);

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
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      char temp = getchar();
      Board[i][j] = (int)temp - 48;
    }
    getchar();
  }
}

void solve() {
  dfs(1, 1, 0);
  cout << answer << endl;
}

void dfs(int y, int x, int value) {
  // cout << "now : " << y << " " << x <<endl;
  if (y == N && x == M + 1) {
    // cout << "value : " << value << endl << endl;
    if (answer < value) {
      answer = value;
    }
    return;
  }
  if (x == M + 1) {
    dfs(y + 1, 1, value);
    return;
  }

  if (visited[y][x]) {
    dfs(y, x + 1, value);
    return;
  }

  //가로로 하나씩 넣어보기
  int temp = Board[y][x];
  // cout << "start : " << temp << endl;
  visited[y][x] = true;
  dfs(y, x + 1, value + temp);

  int i;
  for (i = x + 1; i <= M; i++) {
    if (visited[y][i]) {
      break;
    }
    visited[y][i] = true;
    temp = temp * 10 + Board[y][i];
    // cout << "temp : " << temp << endl;
    dfs(y, i + 1, value + temp);
  }
  for (int j = x + 1; j <= i - 1; j++) {
    visited[y][j] = false;
  }

  temp = Board[y][x];

  //세로로 하나씩 넣어보기
  for (i = y + 1; i <= N; i++) {
    if (visited[i][x]) {
      break;
    }
    visited[i][x] = true;
    temp = temp * 10 + Board[i][x];
    dfs(y, x + 1, value + temp);
  }
  for (int j = y + 1; j <= i - 1; j++) {
    visited[j][x] = false;
  }

  visited[y][x] = false;
  // cout << y << " " << x << " out" << endl;
}
