#include <iostream>

using namespace std;

#define endl '\n'

int board[5][5];
int answer = 0;
bool numbers[1000000] = {
    false,
};

void input();
void solve();
bool isValidIndex(int y, int x) { return y < 5 && y >= 0 && x < 5 && x >= 0; }
void dfs(int y, int x, int digits, int number);

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      dfs(i, j, 0, board[i][j]);
    }
  }
  cout << answer << endl;
}

void dfs(int y, int x, int digits, int number) {
  cout << "y, x : " << y << " " << x << endl;
  if (digits == 5) {
    if (!numbers[number]) {
      numbers[number] = true;
      answer++;
    }
    return;
  }

  for (int d = 0; d < 4; d++) {
    int next_y = y + dir[d][0];
    int next_x = x + dir[d][1];

    if (isValidIndex(next_y, next_x)) {
      cout << "next_y, next_x : " << next_y << " " << next_x << endl;
      dfs(next_y, next_x, digits + 1, number * 10 + board[next_y][next_x]);
    }
  }
  return;
}